// ignore_for_file: public_member_api_docs, sort_constructors_first
// ignore_for_file: depend_on_referenced_packages

import 'dart:ffi';
import 'dart:io';

import "package:ffi/ffi.dart";
import 'package:flutter/material.dart';
import 'package:rtk_mavlink/mavlink_classes.dart';

import 'rtk_mavlink_bindings_generated.dart';

const String _libName = 'rtk_mavlink';

bool isHeartbeatAlreadyRecived = false;

(Array<Uint8>, int) requestAttitude() {
  try {
    var attitudePointer = _bindings.request_attitude();

    debugPrint(attitudePointer.tx_msg_len.toString());

    return (attitudePointer.tx_msg_buffer, attitudePointer.tx_msg_len);
  } catch (e, st) {
    debugPrint(e.toString());
    debugPrintStack(stackTrace: st);
    return (const Array<Uint8>(0), 0);
  }
}

(Array<Uint8>, int) requestSysStatus() {
  try {
    var sysStatusPointer = _bindings.request_sys_status();

    return (sysStatusPointer.tx_msg_buffer, sysStatusPointer.tx_msg_len);
  } catch (e, st) {
    debugPrintStack(stackTrace: st);
    return (const Array<Uint8>(0), 0);
  }
}

(Array<Uint8>, int) requestGpsStatus() {
  try {
    var gpsStatusPointer = _bindings.request_gps_status();

    return (gpsStatusPointer.tx_msg_buffer, gpsStatusPointer.tx_msg_len);
  } catch (e, st) {
    debugPrintStack(stackTrace: st);
    return (const Array<Uint8>(0), 0);
  }
}

(Array<Uint8>, int) requestGlobalPositionInt() {
  try {
    var globalPositionIntPointer = _bindings.request_global_position_int();

    return (
      globalPositionIntPointer.tx_msg_buffer,
      globalPositionIntPointer.tx_msg_len
    );
  } catch (e, st) {
    debugPrintStack(stackTrace: st);
    return (const Array<Uint8>(0), 0);
  }
}

MavlinkHeartbeat? mavlinkHeartbeat;
MavlinkSysStatus? mavlinkSystStatus;
MavlinkGpsStatus? mavlinkGpsStatus;
MavlinkAttitude? mavlinkAttitude;
MavlinkGlobalPositionInt? mavlinkGlobalPositionInt;

List<MavlinkMessage> updateData(List<int> newBytes) {
  List<MavlinkMessage> messages = [];

  for (var i = 0; i < newBytes.length; i++) {
    _bindings.update_data(newBytes[i]);

    mavlinkHeartbeat = MavlinkHeartbeat(
        type: _bindings.rx_heartbeat.type,
        autopilot: _bindings.rx_heartbeat.autopilot,
        baseMode: _bindings.rx_heartbeat.base_mode,
        customMode: _bindings.rx_heartbeat.custom_mode,
        systemStatus: _bindings.rx_heartbeat.system_status,
        mavlinkVersion: _bindings.rx_heartbeat.mavlink_version);

    mavlinkSystStatus = MavlinkSysStatus(
        onboardControlSensorsPresent:
            _bindings.rx_sys_status.onboard_control_sensors_present,
        onboardControlSensorsEnabled:
            _bindings.rx_sys_status.onboard_control_sensors_enabled,
        onboardControlSensorsHealth:
            _bindings.rx_sys_status.onboard_control_sensors_health,
        load: _bindings.rx_sys_status.load,
        voltageBattery: _bindings.rx_sys_status.voltage_battery,
        currentBattery: _bindings.rx_sys_status.current_battery,
        batteryRemaining: _bindings.rx_sys_status.battery_remaining,
        dropRateComm: _bindings.rx_sys_status.drop_rate_comm,
        errorsComm: _bindings.rx_sys_status.errors_comm,
        errorsCount1: _bindings.rx_sys_status.errors_count1,
        errorsCount2: _bindings.rx_sys_status.errors_count2,
        errorsCount3: _bindings.rx_sys_status.errors_count3,
        errorsCount4: _bindings.rx_sys_status.errors_count4);

    mavlinkGpsStatus = MavlinkGpsStatus(
        satellitesVisible: _bindings.rx_gps_status.satellites_visible,
        satelliteUsed: convertFfiArrayToListInt(
            _bindings.rx_gps_status.satellite_used, 20),
        satellitePrn:
            convertFfiArrayToListInt(_bindings.rx_gps_status.satellite_prn, 20),
        satelliteElevation: convertFfiArrayToListInt(
            _bindings.rx_gps_status.satellite_elevation, 20),
        satelliteAzimuth: convertFfiArrayToListInt(
            _bindings.rx_gps_status.satellite_azimuth, 20),
        satelliteSnr: convertFfiArrayToListInt(
            _bindings.rx_gps_status.satellite_snr, 20));

    mavlinkAttitude = MavlinkAttitude(
        timeBootMs: _bindings.rx_attitude.time_boot_ms,
        roll: _bindings.rx_attitude.roll,
        pitch: _bindings.rx_attitude.pitch,
        yaw: _bindings.rx_attitude.yaw,
        rollSpeed: _bindings.rx_attitude.rollspeed,
        pitchSpeed: _bindings.rx_attitude.pitchspeed,
        yawSpeed: _bindings.rx_attitude.yawspeed);

    mavlinkGlobalPositionInt = MavlinkGlobalPositionInt(
        timeBootMs: _bindings.rx_global_position_int.time_boot_ms,
        lat: _bindings.rx_global_position_int.lat,
        lon: _bindings.rx_global_position_int.lon,
        alt: _bindings.rx_global_position_int.alt,
        relativeAlt: _bindings.rx_global_position_int.relative_alt,
        vx: _bindings.rx_global_position_int.vx,
        vy: _bindings.rx_global_position_int.vy,
        vz: _bindings.rx_global_position_int.vz,
        hdg: _bindings.rx_global_position_int.hdg);

    debugPrint("roll: ${mavlinkAttitude!.roll}");
    debugPrint("pitch: ${mavlinkAttitude!.pitch}");
    debugPrint("yaw: ${mavlinkAttitude!.yaw}");

    messages.add(mavlinkHeartbeat!);
    messages.add(mavlinkSystStatus!);
    messages.add(mavlinkGpsStatus!);
    messages.add(mavlinkAttitude!);
    messages.add(mavlinkGlobalPositionInt!);
  }

  return messages;
}

List<int> convertFfiArrayToListInt(Array<Uint8> ffiArray, int length) {
  // Инициализация пустого списка для хранения результата
  List<int> resultList = [];

  // Перебор элементов ffi.Array и добавление их в список
  for (int i = 0; i < length; i++) {
    resultList.add(ffiArray[i]);
  }

  return resultList;
}

/// The dynamic library in which the symbols for [RtkMavlinkBindings] can be found.
final DynamicLibrary _dylib = () {
  if (Platform.isMacOS || Platform.isIOS) {
    return DynamicLibrary.open('$_libName.framework/$_libName');
  }
  if (Platform.isAndroid || Platform.isLinux) {
    return DynamicLibrary.open('lib$_libName.so');
  }
  if (Platform.isWindows) {
    return DynamicLibrary.open('$_libName.dll');
  }
  throw UnsupportedError('Unknown platform: ${Platform.operatingSystem}');
}();

/// The bindings to the native functions in [_dylib].
final RtkMavlinkBindings _bindings = RtkMavlinkBindings(_dylib);

// ignore_for_file: public_member_api_docs, sort_constructors_first
abstract class MavlinkMessage {}

class MavlinkHeartbeat extends MavlinkMessage {
  int type;
  int autopilot;
  int baseMode;
  int customMode;
  int systemStatus;
  int mavlinkVersion;

  MavlinkHeartbeat({
    required this.type,
    required this.autopilot,
    required this.baseMode,
    required this.customMode,
    required this.systemStatus,
    required this.mavlinkVersion,
  });
}

class MavlinkSysStatus extends MavlinkMessage {
  int onboardControlSensorsPresent;
  int onboardControlSensorsEnabled;
  int onboardControlSensorsHealth;
  int load;
  int voltageBattery;
  int currentBattery;
  int batteryRemaining;
  int dropRateComm;
  int errorsComm;
  int errorsCount1;
  int errorsCount2;
  int errorsCount3;
  int errorsCount4;

  MavlinkSysStatus({
    required this.onboardControlSensorsPresent,
    required this.onboardControlSensorsEnabled,
    required this.onboardControlSensorsHealth,
    required this.load,
    required this.voltageBattery,
    required this.currentBattery,
    required this.batteryRemaining,
    required this.dropRateComm,
    required this.errorsComm,
    required this.errorsCount1,
    required this.errorsCount2,
    required this.errorsCount3,
    required this.errorsCount4,
  });
}

class MavlinkGpsStatus extends MavlinkMessage {
  int satellitesVisible;
  List<int> satelliteUsed;
  List<int> satellitePrn;
  List<int> satelliteElevation;
  List<int> satelliteAzimuth;
  List<int> satelliteSnr;

  MavlinkGpsStatus({
    required this.satellitesVisible,
    required this.satelliteUsed,
    required this.satellitePrn,
    required this.satelliteElevation,
    required this.satelliteAzimuth,
    required this.satelliteSnr,
  });
}

class MavlinkAttitude extends MavlinkMessage {
  int timeBootMs;
  double roll;
  double pitch;
  double yaw;
  double rollSpeed;
  double pitchSpeed;
  double yawSpeed;

  MavlinkAttitude({
    required this.timeBootMs,
    required this.roll,
    required this.pitch,
    required this.yaw,
    required this.rollSpeed,
    required this.pitchSpeed,
    required this.yawSpeed,
  });
}

class MavlinkGlobalPositionInt extends MavlinkMessage {
  int timeBootMs;
  int lat;
  int lon;
  int alt;
  int relativeAlt;
  int vx;
  int vy;
  int vz;
  int hdg;

  MavlinkGlobalPositionInt({
    required this.timeBootMs,
    required this.lat,
    required this.lon,
    required this.alt,
    required this.relativeAlt,
    required this.vx,
    required this.vy,
    required this.vz,
    required this.hdg,
  });
}

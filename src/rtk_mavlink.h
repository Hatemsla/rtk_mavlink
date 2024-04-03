#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "generated-lib/ardupilotmega/mavlink.h"
#include "generated-lib/mavlink_helpers.h"
// #include "rtk_mavlink_variables.h"

#if _WIN32
#include <windows.h>
#else
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#endif

#if _WIN32
#define FFI_PLUGIN_EXPORT __declspec(dllexport)
#else
#define FFI_PLUGIN_EXPORT
#endif

mavlink_message_t tx_msg;
mavlink_message_t rx_msg;
mavlink_status_t rx_status;
mavlink_heartbeat_t rx_heartbeat;
mavlink_sys_status_t rx_sys_status;
mavlink_gps_status_t rx_gps_status;
mavlink_attitude_t rx_attitude;
mavlink_global_position_int_t rx_global_position_int;
mavlink_system_time_t rx_system_time;
mavlink_ping_t rx_ping;
mavlink_change_operator_control_t rx_change_operator_control;
mavlink_change_operator_control_ack_t rx_change_operator_control_ack;
mavlink_auth_key_t rx_auth_key;
mavlink_param_request_read_t rx_param_request_read;
mavlink_param_request_list_t rx_param_request_list;
mavlink_param_value_t rx_param_value;
mavlink_param_set_t rx_param_set;
mavlink_gps_raw_int_t rx_gps_raw_int;
mavlink_scaled_imu_t rx_scaled_imu;
mavlink_raw_imu_t rx_raw_imu;
mavlink_raw_pressure_t rx_raw_pressure;
mavlink_scaled_pressure_t rx_scaled_pressure;
mavlink_attitude_quaternion_t rx_attitude_quaternion;
mavlink_local_position_ned_t rx_local_position_ned;
mavlink_rc_channels_scaled_t rx_rc_channels_scaled;
mavlink_rc_channels_raw_t rx_rc_channels_raw;
mavlink_servo_output_raw_t rx_servo_output_raw;
mavlink_mission_request_partial_list_t rx_mission_request_partial_list;
mavlink_mission_write_partial_list_t rx_mission_write_partial_list;
mavlink_mission_current_t rx_mission_current;
mavlink_mission_request_list_t rx_mission_request_list;
mavlink_mission_count_t rx_mission_count;
mavlink_mission_clear_all_t rx_mission_clear_all;
mavlink_mission_item_reached_t rx_mission_item_reached;
mavlink_mission_ack_t rx_mission_ack;
mavlink_set_gps_global_origin_t rx_set_gps_global_origin;
mavlink_gps_global_origin_t rx_gps_global_origin;
mavlink_param_map_rc_t rx_param_map_rc;
mavlink_mission_request_int_t rx_mission_request_int;
mavlink_safety_set_allowed_area_t rx_safety_set_allowed_area;
mavlink_safety_allowed_area_t rx_safety_allowed_area;
mavlink_attitude_quaternion_cov_t rx_attitude_quaternion_cov;
mavlink_nav_controller_output_t rx_nav_controller_output;
mavlink_global_position_int_cov_t rx_global_position_int_cov;
mavlink_local_position_ned_cov_t rx_local_position_ned_cov;
mavlink_rc_channels_t rx_rc_channels;
mavlink_manual_control_t rx_manual_control;
mavlink_rc_channels_override_t rx_rc_channels_override;
mavlink_mission_item_int_t rx_mission_item_int;
mavlink_vfr_hud_t rx_vfr_hud;
mavlink_command_int_t rx_command_int;
mavlink_command_long_t rx_command_long;
mavlink_manual_setpoint_t rx_manual_setpoint;
mavlink_set_attitude_target_t rx_set_attitude_target;
mavlink_attitude_target_t rx_attitude_target;
mavlink_set_position_target_local_ned_t rx_set_position_target_local_ned;
mavlink_position_target_local_ned_t rx_position_target_local_ned;
mavlink_set_position_target_global_int_t rx_set_position_target_global_int;
mavlink_position_target_global_int_t rx_position_target_global_int;
mavlink_local_position_ned_system_global_offset_t rx_local_position_ned_system_global_offset;
mavlink_hil_controls_t rx_hil_controls;
mavlink_hil_rc_inputs_raw_t rx_hil_rc_inputs_raw;
mavlink_hil_actuator_controls_t rx_hil_actuator_controls;
mavlink_hil_optical_flow_t rx_hil_optical_flow;
mavlink_global_vision_position_estimate_t rx_global_vision_position_estimate;
mavlink_vision_position_estimate_t rx_vision_position_estimate;
mavlink_vision_speed_estimate_t rx_vision_speed_estimate;
mavlink_vision_position_estimate_t rx_vision_position_estimate;
mavlink_optical_flow_t rx_optical_flow;
mavlink_hil_sensor_t rx_hil_sensor;
mavlink_sim_state_t rx_sim_state;
mavlink_radio_status_t rx_radio_status;
mavlink_file_transfer_protocol_t rx_file_transfer_protocol;
mavlink_timesync_t rx_timesync;
mavlink_camera_trigger_t rx_camera_trigger;
mavlink_hil_gps_t rx_hil_gps;
mavlink_hil_optical_flow_t rx_hil_optical_flow;
mavlink_hil_state_quaternion_t rx_hil_state_quaternion;
mavlink_scaled_imu2_t rx_scaled_imu2;
mavlink_log_request_list_t rx_log_request_list;
mavlink_log_entry_t rx_log_entry;
mavlink_log_request_data_t rx_log_request_data;
mavlink_log_data_t rx_log_data;
mavlink_log_erase_t rx_log_erase;
mavlink_log_request_end_t rx_log_request_end;
mavlink_gps2_raw_t rx_gps2_raw;
mavlink_power_status_t rx_power_status;
mavlink_serial_control_t rx_serial_control;
mavlink_gps_rtk_t rx_gps_rtk;
mavlink_gps2_rtk_t rx_gps2_rtk;
mavlink_scaled_imu3_t rx_scaled_imu3;
mavlink_data_transmission_handshake_t rx_data_transmission_handshake;
mavlink_encapsulated_data_t rx_encapsulated_data;
mavlink_distance_sensor_t rx_distance_sensor;
mavlink_terrain_request_t rx_terrain_request;
mavlink_terrain_data_t rx_terrain_data;
mavlink_terrain_check_t rx_terrain_check;
mavlink_terrain_report_t rx_terrain_report;
mavlink_scaled_pressure2_t rx_scaled_pressure2;
mavlink_att_pos_mocap_t rx_att_pos_mocap;
mavlink_set_actuator_control_target_t rx_set_actuator_control_target;
mavlink_actuator_control_target_t rx_actuator_control_target;
mavlink_altitude_t rx_altitude;
mavlink_resource_request_t rx_resource_request;
mavlink_scaled_pressure3_t rx_scaled_pressure3;
mavlink_follow_target_t rx_follow_target;
mavlink_control_system_state_t rx_control_system_state;
mavlink_battery_status_t rx_battery_status;
mavlink_autopilot_version_t rx_autopilot_version;
mavlink_landing_target_t rx_landing_target;
mavlink_fence_status_t rx_fence_status;
mavlink_mag_cal_report_t rx_mag_cal_report;
mavlink_efi_status_t rx_efi_status;
mavlink_estimator_status_t rx_estimator_status;
mavlink_wind_cov_t rx_wind_cov;
mavlink_gps_input_t rx_gps_input;
mavlink_gps_rtcm_data_t rx_gps_rtcm_data;
mavlink_high_latency2_t rx_high_latency2;
mavlink_vibration_t rx_vibration;
mavlink_home_position_t rx_home_position;
mavlink_message_interval_t rx_message_interval;
mavlink_extended_sys_state_t rx_extended_sys_state;
mavlink_adsb_vehicle_t rx_adsb_vehicle;
mavlink_collision_t rx_collision;
mavlink_v2_extension_t rx_v2_extension;
mavlink_memory_vect_t rx_memory_vect;
mavlink_debug_vect_t rx_debug_vect;
mavlink_named_value_float_t rx_named_value_float;
mavlink_named_value_int_t rx_named_value_int;
mavlink_statustext_t rx_statustext;
mavlink_debug_t rx_debug;
mavlink_setup_signing_t rx_setup_signing;
mavlink_button_change_t rx_button_change;
mavlink_camera_information_t rx_camera_information;
mavlink_camera_settings_t rx_camera_settings;
mavlink_storage_information_t rx_storage_information;
mavlink_camera_capture_status_t rx_camera_capture_status;
mavlink_camera_image_captured_t rx_camera_image_captured;
mavlink_flight_information_t rx_flight_information;
mavlink_logging_data_t rx_logging_data;
mavlink_logging_data_acked_t rx_logging_data_acked;
mavlink_logging_ack_t rx_logging_ack;
mavlink_video_stream_information_t rx_video_stream_information;
mavlink_video_stream_status_t rx_video_stream_status;
mavlink_camera_fov_status_t rx_camera_fov_status;
mavlink_camera_tracking_image_status_t rx_camera_tracking_image_status;
mavlink_camera_tracking_geo_status_t rx_camera_tracking_geo_status;
mavlink_gimbal_manager_information_t rx_gimbal_manager_information;
mavlink_gimbal_manager_status_t rx_gimbal_manager_status;
mavlink_gimbal_manager_set_attitude_t rx_gimbal_manager_set_attitude;
mavlink_gimbal_device_information_t rx_gimbal_device_information;
mavlink_gimbal_device_set_attitude_t rx_gimbal_device_set_attitude;
mavlink_gimbal_device_attitude_status_t rx_gimbal_device_attitude_status;
mavlink_autopilot_state_for_gimbal_device_t rx_autopilot_state_for_gimbal_device;
mavlink_gimbal_manager_set_pitchyaw_t rx_gimbal_manager_set_pitchyaw;
mavlink_gimbal_manager_set_manual_control_t rx_gimbal_manager_set_manual_control;
mavlink_wifi_config_ap_t rx_wifi_config_ap;
mavlink_ais_vessel_t rx_ais_vessel;
mavlink_uavcan_node_status_t rx_uavcan_node_status;
mavlink_uavcan_node_info_t rx_uavcan_node_info;
mavlink_param_ext_request_read_t rx_param_ext_request_read;
mavlink_param_ext_request_list_t rx_param_ext_request_list;
mavlink_param_ext_value_t rx_param_ext_value;
mavlink_param_ext_set_t rx_param_ext_set;
mavlink_param_ext_ack_t rx_param_ext_ack;
mavlink_obstacle_distance_t rx_obstacle_distance;
mavlink_odometry_t rx_odometry;
mavlink_isbd_link_status_t rx_isbd_link_status;
mavlink_raw_rpm_t rx_raw_rpm;
mavlink_utm_global_position_t rx_utm_global_position;
mavlink_debug_float_array_t rx_debug_float_array;
mavlink_generator_status_t rx_generator_status;
mavlink_actuator_output_status_t rx_actuator_output_status;
mavlink_tunnel_t rx_tunnel;
mavlink_can_frame_t rx_can_frame;
mavlink_canfd_frame_t rx_canfd_frame;
mavlink_can_filter_modify_t rx_can_filter_modify;
mavlink_wheel_distance_t rx_wheel_distance;
mavlink_winch_status_t rx_winch_status;
mavlink_open_drone_id_basic_id_t rx_open_drone_id_basic_id;
mavlink_open_drone_id_location_t rx_open_drone_id_location;
mavlink_open_drone_id_authentication_t rx_open_drone_id_authentication;
mavlink_open_drone_id_self_id_t rx_open_drone_id_self_id;
mavlink_open_drone_id_system_t rx_open_drone_id_system;
mavlink_open_drone_id_operator_id_t rx_open_drone_id_operator_id;
mavlink_open_drone_id_message_pack_t rx_open_drone_id_message_pack;
mavlink_open_drone_id_arm_status_t rx_open_drone_id_arm_status;
mavlink_open_drone_id_system_update_t rx_open_drone_id_system_update;
mavlink_hygrometer_sensor_t rx_hygrometer_sensor;

uint8_t sysid_apm;  // id дрона
uint8_t compid_apm; // id автопилота

typedef struct
{
    uint8_t tx_msg_buffer[MAVLINK_MAX_PACKET_LEN];
    int tx_msg_len;
} send_msg;

/// @brief Метод для обновления данных
/// @param new_byte байт из приемного канала
/// @return
FFI_PLUGIN_EXPORT void update_data(uint8_t new_byte);

/// @brief Запрос данных о положении
/// @return структура send_msg
FFI_PLUGIN_EXPORT send_msg request_attitude();

/// @brief Запрос данных о системном статусе
/// @return структура send_msg
FFI_PLUGIN_EXPORT send_msg request_sys_status();

/// @brief Запрос данных о наваигации
/// @return структура send_msg
FFI_PLUGIN_EXPORT send_msg request_gps_status();

/// @brief Запрос данных о глобальной позиции
/// @return структура send_msg
FFI_PLUGIN_EXPORT send_msg request_global_position_int();

/// @brief Запрос данных о локальной позиции
/// @return структура send_msg
FFI_PLUGIN_EXPORT send_msg request_local_position_ned();
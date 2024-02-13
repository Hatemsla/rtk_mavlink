#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "generated-lib/ardupilotmega/mavlink.h"
#include "generated-lib/mavlink_helpers.h"

#if _WIN32
#include <windows.h>
#else
#include <pthread.h>
#include <unistd.h>
#endif

#if _WIN32
#define FFI_PLUGIN_EXPORT __declspec(dllexport)
#else
#define FFI_PLUGIN_EXPORT
#endif

FFI_PLUGIN_EXPORT void send_heardbeat();

FFI_PLUGIN_EXPORT void send_local_pose(float x, float y, float z);

FFI_PLUGIN_EXPORT bool point_is_reached();
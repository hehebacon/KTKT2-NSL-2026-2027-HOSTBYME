#pragma once

#include <Arduino.h>

namespace Config {
constexpr uint32_t SERIAL_BAUD = 115200;
constexpr uint32_t STATUS_INTERVAL_MS = 1000;
constexpr uint32_t COMMAND_LINE_MAX = 96;

// These are project targets, not verified aircraft performance.
constexpr uint16_t TARGET_USEFUL_PAYLOAD_G = 250;
constexpr uint16_t TARGET_FLIGHT_TIME_MIN = 10;

// Safe default: this companion firmware never enables actuator outputs.
constexpr bool ACTUATOR_OUTPUTS_IMPLEMENTED = false;
constexpr bool FLIGHT_CONTROL_IMPLEMENTED = false;
constexpr bool STARTUP_INHIBITED = true;

inline const char* firmwareName() {
#ifdef FIRMWARE_NAME
  return FIRMWARE_NAME;
#else
  return "KTKT2-ESP32-COMPANION";
#endif
}

inline const char* firmwareVersion() {
#ifdef FIRMWARE_VERSION
  return FIRMWARE_VERSION;
#else
  return "0.1.0";
#endif
}
}  // namespace Config

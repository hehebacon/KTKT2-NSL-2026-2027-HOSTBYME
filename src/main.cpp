#include <Arduino.h>
#include "Config.h"

namespace {
enum class SystemState : uint8_t {
  BOOTING,
  DIAGNOSTIC,
  INHIBITED
};

SystemState state = SystemState::BOOTING;
uint32_t bootMs = 0;
uint32_t lastStatusMs = 0;
String commandBuffer;

const char* stateName(SystemState value) {
  switch (value) {
    case SystemState::BOOTING: return "BOOTING";
    case SystemState::DIAGNOSTIC: return "DIAGNOSTIC";
    case SystemState::INHIBITED: return "INHIBITED";
  }
  return "UNKNOWN";
}

void printHelp() {
  Serial.println();
  Serial.println("Commands:");
  Serial.println("  help     - show commands");
  Serial.println("  status   - show firmware and safety state");
  Serial.println("  selftest - run software-only checks");
  Serial.println();
}

void printStatus() {
  Serial.println("--- SYSTEM STATUS ---");
  Serial.printf("Firmware: %s\n", Config::firmwareName());
  Serial.printf("Version:  %s\n", Config::firmwareVersion());
  Serial.printf("Uptime:   %lu ms\n",
                static_cast<unsigned long>(millis() - bootMs));
  Serial.printf("State:    %s\n", stateName(state));
  Serial.printf("Useful payload target: %u g (unverified)\n",
                Config::TARGET_USEFUL_PAYLOAD_G);
  Serial.printf("Flight-time target: > %u min (unverified)\n",
                Config::TARGET_FLIGHT_TIME_MIN);
  Serial.println("Flight controller: NOT IMPLEMENTED");
  Serial.println("Motor/ESC outputs: NOT IMPLEMENTED");
  Serial.println("Safety inhibit: ON");
  Serial.println("---------------------");
}

bool runSoftwareSelfTest() {
  bool ok = true;
  ok = ok && (Config::SERIAL_BAUD > 0);
  ok = ok && (Config::STATUS_INTERVAL_MS >= 100);
  ok = ok && Config::STARTUP_INHIBITED;
  ok = ok && !Config::ACTUATOR_OUTPUTS_IMPLEMENTED;
  ok = ok && !Config::FLIGHT_CONTROL_IMPLEMENTED;

  Serial.printf("Software self-test: %s\n", ok ? "PASS" : "FAIL");
  Serial.println("Note: this does not test sensors, motors, battery, or flight.");
  return ok;
}

void handleCommand(String command) {
  command.trim();
  command.toLowerCase();

  if (command == "help") {
    printHelp();
  } else if (command == "status") {
    printStatus();
  } else if (command == "selftest") {
    runSoftwareSelfTest();
  } else if (command.length() == 0) {
    // Ignore blank lines.
  } else {
    Serial.printf("Unknown command: %s\n", command.c_str());
    Serial.println("Type 'help' for available commands.");
  }
}

void pollSerial() {
  while (Serial.available() > 0) {
    const char c = static_cast<char>(Serial.read());

    if (c == '\r' || c == '\n') {
      if (commandBuffer.length() > 0) {
        handleCommand(commandBuffer);
        commandBuffer = "";
      }
    } else if (c >= 32 && c <= 126) {
      if (commandBuffer.length() < Config::COMMAND_LINE_MAX) {
        commandBuffer += c;
      } else {
        commandBuffer = "";
        Serial.println("Input too long; command discarded.");
      }
    }
  }
}
}  // namespace

void setup() {
  Serial.begin(Config::SERIAL_BAUD);
  bootMs = millis();
  state = SystemState::INHIBITED;

  const uint32_t waitStart = millis();
  while (!Serial && millis() - waitStart < 1500) {
    delay(10);
  }

  Serial.println();
  Serial.println("KTKT2 ESP32 Companion Firmware");
  Serial.println("Startup safety inhibit is ON.");
  Serial.println("No flight control or actuator outputs are present.");
  printHelp();
  printStatus();
}

void loop() {
  pollSerial();

  const uint32_t now = millis();
  if (now - lastStatusMs >= Config::STATUS_INTERVAL_MS) {
    lastStatusMs = now;
    // Keep the system inhibited until a verified architecture and
    // safety-reviewed integration are implemented.
    state = SystemState::INHIBITED;
  }

  delay(2);
}

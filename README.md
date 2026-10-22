# KTKT2 NSL 2026–2027 — ESP32 Companion Firmware

> **Status: software scaffold / bench diagnostics only. Not flight-ready.**

This repository starts with a modular ESP32 companion firmware so software work can begin before hardware is purchased. It does **not** implement flight stabilization, motor mixing, or direct ESC/propeller control. Use a compatible, established flight controller for flight-critical control; integrate the ESP32 only through a documented interface after the hardware is selected.

## Current goals

- Establish a clean PlatformIO + Arduino project structure.
- Provide serial diagnostics and a visible safety-inhibited state.
- Keep hardware-dependent functions isolated until the exact ESP32 board and sensors are known.
- Track the competition target: **250 g useful payload** and **more than 10 minutes flight time** as goals to verify by calculation and measured tests, not assumptions.

## Build

1. Install VS Code and PlatformIO.
2. Select the exact ESP32 board in `platformio.ini` before compiling on hardware.
3. Build the project. The default board identifier is a provisional ESP32 DevKit profile; confirm it matches your actual board before flashing.
4. Connect over USB serial at 115200 baud and enter `help`.

Supported diagnostic commands: `help`, `status`, `selftest`.

## Safety and validation

- No motor or ESC outputs are implemented.
- Do not connect propellers during electronics bench checks.
- Before any flight testing, review local rules with a responsible adult, use a permitted test area away from people, and follow all manufacturer instructions.
- A successful compile does not prove the aircraft can lift 250 g or fly for 10+ minutes.
- Do not buy a battery, motors, ESCs, propellers, or flight controller until the aircraft mass budget, compatibility, and power requirements have been reviewed.

## Next milestones

1. Confirm exact ESP32 model and intended flight-controller architecture.
2. Add board-specific sensor diagnostics once sensors are selected.
3. Create a verified bill of materials and mass/power budget.
4. Run bench checks and document measured results.
5. Only then plan supervised, low-risk validation tests.

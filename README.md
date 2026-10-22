# KTKT2 NSL 2026–2027 — ESP32 Companion Firmware

> **Status: early software scaffold for diagnostics. Not flight-ready.**

The goal is to begin software work before purchasing hardware. This firmware does **not** implement flight stabilization, motor mixing, or direct ESC/propeller control.

## Recommended architecture

- Use a compatible, documented flight controller for flight-critical stabilization and motor control.
- Use the ESP32 as a companion for diagnostics, telemetry/logging, and competition-facing status display.
- Integrate only after exact board models, voltage levels, interfaces, and protocol documentation are confirmed.
- Keep outputs inhibited until a responsible adult and qualified reviewer have checked the complete system.

## Targets (not yet demonstrated)

- Useful payload: **250 g**.
- Flight duration: **more than 10 minutes**.
- All-up mass, power draw, endurance, and payload capability remain unverified.

## Build and serial diagnostics

1. Install VS Code and PlatformIO.
2. The current `esp32dev` board setting is provisional. Confirm the exact board before compiling/flashing.
3. Build the project and connect through USB serial at 115200 baud.
4. Try `help`, `status`, and `selftest`.

The self-test checks firmware constants and safety defaults only. It does not test any physical component.

## Safety and legal review

- No motor or ESC outputs are implemented.
- Do not install propellers during electronics bench checks.
- A successful compile is not evidence of flight safety, payload capacity, or endurance.
- Before any physical test or flight, have a responsible adult review applicable Vietnamese registration, permit, operator and test-area requirements. Keep testing away from people and follow manufacturer instructions.
- Do not order propulsion or battery components until mass, power, and compatibility reviews are complete.

## Milestones

1. Compile and review the software scaffold.
2. Choose the architecture and exact ESP32 board.
3. Establish a reviewed mass/power budget and component compatibility matrix.
4. Add only the documented telemetry interface needed by the chosen flight controller.
5. Test serial and diagnostics on a bench with no propellers.
6. Document measured evidence; never report a target as achieved before testing.

# Companion Telemetry Interface — Draft

This file is a design boundary, not a claim that a specific flight controller is compatible.

## Principles

- Flight-critical stabilization and motor outputs remain on the selected flight controller.
- ESP32 reads telemetry and reports companion health only.
- Start in read-only mode. Do not send arming, mode-change, actuator, or flight commands from this scaffold.
- Use only the chosen controller's official, version-matched protocol documentation.
- Define the UART pins, baud rate, voltage levels, message framing, checksum, timeout, and stale-data behavior only after the exact hardware is selected.
- Reject malformed, oversized, unsupported, or stale messages.
- Missing telemetry must show as unavailable/stale; never invent zero values as if they were valid sensor readings.
- Do not connect signal wires until voltage levels, common ground, and pinout are verified against both datasheets.

## Planned read-only data model

- Link status: disconnected / receiving / stale / invalid.
- Flight-controller health: unknown until a valid documented status message is received.
- Battery values: unavailable until sourced from a compatible, verified measurement path.
- Position/attitude: unavailable until a compatible sensor source is confirmed.
- Companion firmware version and uptime.

## Acceptance criteria

- [ ] Protocol and firmware version recorded.
- [ ] Electrical compatibility reviewed.
- [ ] Invalid frames are rejected.
- [ ] Stale telemetry is clearly indicated.
- [ ] No actuator or arming command path exists.
- [ ] Bench tests pass before any supervised aircraft integration.

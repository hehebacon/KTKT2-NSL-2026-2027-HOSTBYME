# Project Plan — Hardware and Verification Gates

## Locked project targets

- Useful payload: 250 g.
- Flight time: greater than 10 minutes.
- Competition: Khéo tay kỹ thuật, 2026–2027.
- Current firmware: ESP32 companion diagnostics only.

These are targets, not achieved results.

## Must confirm before buying parts

- Exact ESP32 board model and operating-voltage requirements.
- Whether a separate flight controller is required by the selected architecture and competition rules.
- Estimated airframe, electronics, battery, wiring, and payload masses.
- Power budget and battery energy estimate with a conservative reserve.
- Compatibility of the selected controller, receiver/link, sensors, ESCs, motors, and battery.
- Applicable local rules, supervision, and safe test site.

## Software validation checklist

- [ ] Compile using the exact selected board profile.
- [ ] Confirm serial startup and command handling.
- [ ] Run `help`, `status`, and `selftest`.
- [ ] Confirm long serial input is rejected safely.
- [ ] Confirm no actuator outputs or flight-control claims exist in this scaffold.
- [ ] Add hardware tests only after actual components and datasheets are known.

## Evidence required before claiming success

- Measured all-up mass and separately measured 250 g useful payload.
- Documented battery and power configuration.
- Repeatable timed test results under supervised and permitted conditions.
- Logs, test conditions, failures, and revisions.
- Demonstration that the payload is carried safely and the flight-time target is met.

## Test order

1. Source review and compile.
2. USB/serial diagnostics with no propellers installed.
3. Sensor and power checks using manufacturer documentation.
4. Supervised stationary checks in a safe, controlled environment.
5. Any flight validation only after a qualified adult reviews the complete system and local requirements.

# Hardware Architecture, Preliminary BOM and Verification Plan

## 1. Design goals

| Requirement | Current status |
|---|---|
| Useful payload 250 g | Target only; not demonstrated |
| Flight time >10 minutes | Target only; not demonstrated |
| ESP32 board | Not purchased / exact model undecided |
| Flight controller | Not selected |
| Airframe / propulsion | Not selected |
| Actual all-up mass and power draw | Unknown |

## 2. Recommended architecture

Use a documented, established flight controller for flight-critical functions. Use ESP32 as a non-flight-critical companion for telemetry, status, logging, and optional competition display. Do not implement motor mixing or flight stabilization in this starter firmware.

Before selecting any physical part, compare the selected controller's documented input voltage, supported firmware, sensors, receiver interface, telemetry protocol, and power module requirements. Do not assume that two boards are electrically or protocol compatible because both use UART/I2C.

## 3. Preliminary bill of materials — categories, not purchase approval

The following is a planning checklist, not a verified shopping cart. Exact models and quantities require a reviewed mass/power budget and adult technical review.

- ESP32 development board with USB programming and documented logic levels.
- Compatible flight controller and its documented power/telemetry accessories.
- Airframe and secure payload mount rated for the intended total mass.
- Propulsion system selected as a matched set from manufacturer data: motors, ESCs, and compatible propellers.
- Battery and balance charger compatible with the selected system, with appropriate safe storage/handling arrangements.
- Receiver/transmitter or another legally permitted, documented control link compatible with the flight controller.
- Required wiring, connectors, mounting hardware, vibration isolation, and protective guards where appropriate.
- Basic bench tools and a suitable multimeter; use with adult supervision.
- Optional ESP32 status display or data-logging accessory only after the core system is verified.

Do **not** buy parts solely from a generic KV rating, advertised thrust number, or a seller's unverified flight-time claim. Ask for the exact motor/propeller/voltage current and thrust data, then have the complete configuration reviewed.

## 4. Mass and energy worksheet

Fill these from datasheets and measured values before ordering:

- Airframe and payload mount mass: ______ g
- Flight controller, receiver, wiring, and ESP32: ______ g
- Propulsion components: ______ g
- Battery mass: ______ g
- Useful payload: 250 g
- Total takeoff mass: sum of all items above
- Battery nominal energy: voltage × amp-hours = ______ Wh
- Measured average electrical power in a supervised test: ______ W
- Estimated duration: usable energy ÷ measured average power; include a conservative reserve and verify with repeatable tests

A paper estimate is only a screening tool; it is not proof of flight time or lift capability.

## 5. Software checks

- [ ] PlatformIO build passes for the exact board selected.
- [ ] Serial monitor starts at 115200 baud.
- [ ] `help`, `status`, and `selftest` behave as documented.
- [ ] Overlong serial lines are discarded until the next newline.
- [ ] Flight-critical outputs remain unimplemented/inhibited.
- [ ] Interface is added only from the selected flight controller's official protocol documentation.
- [ ] Hardware-specific tests are clearly separated from software-only checks.

## 6. Test and evidence gates

1. Source review and build.
2. Bench diagnostics with no propellers installed.
3. Verify power rails and wiring against manufacturer documentation.
4. Validate telemetry with a documented test source before connecting it to the aircraft.
5. Any physical aircraft test must be reviewed and supervised by a responsible adult, take place in a permitted area, and comply with applicable rules.
6. Record actual total mass, payload mass, power data, test conditions, duration, and failures. Do not claim the 250 g / 10 minute targets until supported by safe, repeatable evidence.

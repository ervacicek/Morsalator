# Morsalator 🔑

Make a beginner's level morse code translator using Arduino UNO.

## Components 🌠

- Arduino UNO
- I2C LCD Screen
- Buzzer
- LED
- Breadboard
- 220Ω and/or 10kΩ resistors
- Jumper cables

*Compiler used: __Arduino IDE__*

## Circuit 🔌

Using a breadboard is encouraged, in case GND pin's or 5V/3.3V's of the Arduino UNO are not numerous enough you can multipy them using the + and - lines of the breadboard.

### Pins for components:

**LED(Anode):** 13 _(All digitial pins can be used)_
**LED(Cathode):** 220Ω transistor's one leg, other leg of the transistor must be grounded (GND pin)

**Buzzer(Anode):** 8 _(All digitial pins can be used)_
**Buzzer(Cathode):** GND (here, optionally you can use a transistor, it will affect the volume level of the buzzer)

**LCD Screen:** Connect the VCC pin to 5V, GND to GND, lastly use 2 _analog pins_ for SCA and SCL _(Example: A4 and A5)_

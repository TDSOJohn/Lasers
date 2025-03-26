# Monochrome Laser Bar

This repo contains the schematics, software and cad for the monochrome laser bars used by Virtual Concrete.

Hardware:
- Aluminum body
- Up to 6 laser diodes
- Custom designed pcb with [Arduino Nano](https://docs.arduino.cc/hardware/nano/) and up to 6 laser drivers
- Custom variation of ethernet poe to supply everything with a single RJ45
- DMX over rj45 control mode
- Fun mode

Software:
- Reads DMX input using [DMXSerial](https://github.com/mathertel/DMXSerial)
- Writes dimmer values as PWM
- Fun mode is a simple cycle that increases all channel values up to max and then back at 0 for now

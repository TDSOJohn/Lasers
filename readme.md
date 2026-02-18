# Monochrome Laser Bar

This repo contains the schematics and software for the monochrome laser bars used by VirtualConcrete.

Hardware:
- Aluminum body
- Up to 6 laser diodes
- Custom designed pcb with [Arduino Nano](https://docs.arduino.cc/hardware/nano/) and up to 6 laser drivers
- Custom variation of ethernet poe to supply everything with a single RJ45
- DMX over RJ45 control mode
- Fun mode

Software:
- Reads DMX input using [DMXSerial](https://github.com/mathertel/DMXSerial)
- Writes dimmer values as PWM

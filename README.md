# 3D Printed Seven Segment Display

This project collects the build details for a custom 3D printed seven segment display. The segments are illuminated with "Neo Pixels" (SK6812 or WS2812) driven by an Arduino-compatible based on the ATtiny85. 

## Printing

* Printing: Anycubic i3 Mega
* Slicing: [Ultimaker Cura 3.6](https://ultimaker.com/en/products/ultimaker-cura-software)
** 0.1mm layers
** 20% infill
** EO temp.: 200C
** Bed temp.: 60C

## BOM

* [Digispark ATtiny85 rev. A](https://www.amazon.ca/gp/product/B079JGL17F)
* [SK6812](https://www.pololu.com/file/0J1233/sk6812_datasheet.pdf) neo pixels
* wire, solder, etc.

## Notes

* Arduino 1.8.7
* [Digispark programming](https://digistump.com/wiki/digispark/tutorials/connecting)
** on Ubuntu 18.04 LTS
** follow their guide on setting up [udev rules](https://digistump.com/wiki/digispark/tutorials/linuxtroubleshooting) for the USB connection
** tested with blink (found LED on pin 1: model A)
* should be able to get it to look like a [Trinket](https://learn.adafruit.com/introducing-trinket/introduction), but no progress there
* future idea would be to figure out how to get an updated [micronucleus bootloader](https://github.com/micronucleus/micronucleus) on the ATtiny85 and switch over to AVRDUDE




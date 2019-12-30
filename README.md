# IOT clients 

[![MIT Licensed](https://img.shields.io/badge/license-MIT-brightgreen.svg?style=flat-square)](LICENSE)

## Introduction
This reppistory contains all my Arduino projects that are competable with the `iot-base`. In short the `iot-base` is a project that communicates with these Arduinos via wifi (on condition that they are connected to the same network).

Micro Controllers used:
* [https://store.arduino.cc/arduino-uno-rev3](Arduino Uno)
* [https://docs.zerynth.com/latest/official/board.zerynth.nodemcu3/docs/index.html](NodeMCU v3)
* [https://www.wemos.cc/en/latest/d1/d1_mini.html](Wemos D1 mini)

## Prerequisites
All projects use [https://platformio.org/](Platform IO) which is a ecosystem for embedded development. It includes an IDE with Serial Port Monitor, a Framework/Library Registry and much more. 

In addition, a Platform IO supported micro controller (with WiFi support) is of course required.

## Installation
All the `src-*` folders contain code for a specifc project. When flashing a project into a micro controller the `src_dir` and `default_envs` properties in the `platformio.ini` file need to match the current working enviroment.

* `src_dir` should be equal to `src-*` folder that should be flashed.

* `default_envs` should be equal to the micro controller you want to flash the project into. Possible options are: `nodemcuv2` for a NodeMCU and `d1_mini` for a Wemos d1-mini.

## Projects
Every project is marked as `read-unit` or `updatable-units` for the definition of both terms, refer to the `iot-base` project.

if applicable, a circuit diagram will be shown for a project (coming soon)

### src-light-sensor
A LDR04 light depended resistor is used to send the current light intensity at a set interval.
> Read unit

### src-updatble-led-lamp
A LED strip that can change color based on the request being send. Supported requests: html5 color names / hex codes.
> Updateble unit

## License
The MIT License (MIT). Please see [License File](LICENSE) for more information.
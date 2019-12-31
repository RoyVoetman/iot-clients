# IOT clients 

[![MIT Licensed](https://img.shields.io/badge/license-MIT-brightgreen.svg?style=flat-square)](LICENSE)

## Introduction
This repository contains all my Arduino projects that are compatible with the [iot-base](https://github.com/RoyVoetman/iot-base). In short the `iot-base` is a project that communicates with these Arduinos via wifi (on condition that they are connected to the same network).

## About this project
This application is part of my **IOT dashboard suite**. For more information about what this suite of projects entails a reference is made to the [IOT dashboard suite](https://github.com/RoyVoetman/iot-base/blob/master/docs/IOT%20dashboard%20suite.md).

## Prerequisites
All projects use [Platform IO](https://platformio.org/) which is an ecosystem for embedded development. It includes an IDE with Serial Port Monitor, a Framework/Library Registry and much more. 

In addition, a Platform IO supported micro controller (with WiFi support) is of course required.

Micro controllers I have used:
* [NodeMCU v3](https://docs.zerynth.com/latest/official/board.zerynth.nodemcu3/docs/index.html)
* [Wemos D1 mini](https://www.wemos.cc/en/latest/d1/d1_mini.html)

## Installation
All the `src-*` folders contain code for a specific project. When flashing a project into a micro controller the `src_dir` and `default_envs` properties in the `platformio.ini` file need to match the current working environment.

* `src_dir` should be equal to `src-*` folder that should be flashed.

* `default_envs` should be equal to the micro controller you want to flash the project into. <br> Possible options are: `nodemcuv2` for a NodeMCU and `d1_mini` for a Wemos d1-mini.

## Projects
Every project is marked as `read-unit` or `updatable-units` for the definition of both terms a reference is made to the [iot-base](https://github.com/RoyVoetman/iot-base/blob/master/docs/IOT%20dashboard%20suite.md#read-unit-vs-updatable-unit) docs.

If applicable, a circuit diagram will be provided

### src-light-sensor
A LDR04 light depended resistor is used to send the current light intensity at a set interval.
<br>_**Read unit**_

![](https://www.royvoetman.nl/iot/src-light-sensor.jpg)

### src-updatable-led-lamp
A LED strip that can change color based on the request being send. Supported requests: html5 color names / hex codes.
<br>_**Updatable unit**_

![](https://www.royvoetman.nl/iot/src-updatable-led-lamp.jpg)

## License
The MIT License (MIT). Please see [License File](LICENSE) for more information.

## Authors
* [Roy Voetman](https://www.royvoetman.nl)

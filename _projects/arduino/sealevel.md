---
title: "Sea Level Logger"
date: 2024-12-04
layout: single
classes: narrow
sidebar:
  nav: "docs"

toc: true
toc_label: "Table of Contents"
toc_icon: "microchip" 
---

<!--more-->

## Overview
Climate change has altered the environment we live in from global temperatures to sea levels rising. Tracking the levels in which this is happening is very important if we wish to target and combat the effects. The problem that arises is that traditional data loggers designed to track various weather conditions and tide levels are expensive. This means that less sensors are able to be implemented and less data is collected from affected areas. This lack of data has large, longterm implications on our knowledge of what is happening. This project aims to make cheap and simple data loggers that can help solve this gap in data collection.

## Parts Used
- Arduino Uno
- Temperature & Humidity Sensor (DHT11)
- Seeed Studio SD Card Shield V4
- Anemometer
- 2 LEDs
- 2 Resistors (resistance dependent on LED used)
- Photoresistor
- Wires

## Design Layout

<img src="/assets/images/sealevel_design.png" style="width:auto; height:auto;">

*[Download Schematic]({{ "/assets/pdf/sealevel_design.pdf" | relative_url }})*

## Code

<script src="https://gist.github.com/matthew-d-freeman/3f6a39d138504feaf8b325ea1a02bf31.js"></script>

*[Download Arduino Code]({{ "/assets/code/sealevel.ino" | relative_url }})*

## Summary

Once you have completed assembling the data logger, it is important to test it before moving on to designing a housing for it and implementing it in the field. To do so, plug the Arduino into your computer and allow it to run for a couple minutes to allow multiple data points to be taken. I suggest lowering the reading time to 1 minute and then running the logger for ten minutes. Afterwards, unplug the device and check the excel file on the SD card. Ensure that none of the sensors are giving a negative number error code which would mean they are not working properly. If they are giving a negative number, first ensure that all wires are attached correctly. If they are looking to see if the sensor has any visible damage.

With this excel file of initial results, you can also test to see if the data logger sensor are accurate. If you have another method of measuring the different data points, like a separate thermometer, etc., you can then change the data points from the data logger to be more accurate.

Once these initial test are done, you can replace the SD card in the data logger and begin actually taking data. For deploying the logger in a field, the most important aspects are powering it and keeping it watertight. For powering, I suggest using a 9v battery as they are cheap and easy to implement with the Arduino unit using the included 9v battery wire. For the device housing, cheap plastic Tupperware containers work well for housing. Try to get ones that market themselves as waterproof. These will typically have a rubber ring around where the lid goes to keep an airtight seal. Holes can be drilled in the container to allow the sensors to come out and silicone can be used to cover up those holes afterwards to maintain that waterproof effect.

Congratulations, you’re now ready to start data logging. This device measure wind speed, temperature, humidity, light levels, and distance. This makes it a really good device for measuring the change in tides for local waters. Happy logging!

*[Download Sea Level Instructable]({{ "/assets/pdf/sea_level_instructable.pdf" | relative_url }})*

---

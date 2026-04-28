---
title: "Thermometer"
date: 2026-04-12
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
This one was something simple I had to make for my house. The freezer was acting up and we weren't sure if it was cooling properly. The screen for the temperature readouts on the fridge werent working so I just needed to make a simple thermometer to see if the freezer was cooling.

## Parts Used
- Arduino Uno
- Temperature & Humidity Sensor (DHT11)
- Grove - 16X2 LCD RGB Backlight - Full Color Display
- Breadboard
- Wires

## Design Layout

<img src="/assets/images/thermometer_design.png" style="width:auto; height:auto;">

*[Download Schematics]({{ "/assets/pdf/thermometer_design.pdf" | relative_url }})*

## Code

<script src="https://gist.github.com/matthew-d-freeman/44c9634a72150dea334ec379535902e7.js"></script>

*[Download Arduino Code]({{ "/assets/code/thermometer.ino" | relative_url }})*

## Summary
This was just a quick little project I threw together and it worked pretty well. I did learn that the Arduino Uno starts to shut down somewhere around 25*C.

---


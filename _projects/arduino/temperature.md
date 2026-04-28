---
title: "Temperature and SD Card"
date: 2024-10-9
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
For this project, I was tasked to design a system that could read the temperature of different environments and save it to an SD card. For this I was given a SD card shield that I could just slot ontop of the Arduino Uno. I was to save an excel file onto the SD card with all the temperature information needed to then analyze using RStudio.

## Parts Used
- Arduino Uno
- Temperature & Humidity Sensor (DHT11)
- Seeed Studio SD Card Shield V4
- Wires

## Design Layout

<img src="/assets/images/temperature_design.png" style="width:auto; height:auto;">

## Code
### Arduino Code

<script src="https://gist.github.com/matthew-d-freeman/2308896209afee882e753b1441840c8e.js"></script>

*[Download Arduino Code]({{ "/assets/code/temperature.ino" | relative_url }})*

### RStudio Code

<script src="https://gist.github.com/matthew-d-freeman/02b5ccd1238093c2d91a204b14f95367.js"></script>

*[Download RStudio Code]({{ "/assets/code/temperature.R" | relative_url }})*

## Summary

This project went well except for trying to use the SD card I culdn't get it to work at first no matter what I did. I had to unisntall the Arduino IDE and reinstall it for it to finally work. Other than that, the temprature readings and commiting them to a file worked properly.

---

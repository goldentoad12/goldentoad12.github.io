---
title: "Musical LEDs"
date: 2024-09-22
layout: single
classes: narrow
sidebar:
  nav: "docs"

toc: true
toc_label: "Table of Contents"
toc_icon: "microchip" 
toc_sticky: true
---

<!--more-->

## Overview
For this assignment, we were tasked to use a sound sensor and a series of LEDs to listen to music and have the LEDs light up based off of how much sound was detected. However, to make it more challenging he wanted us to make 2 versions of the code one the is allowed to use if/else statements and one that wasn't allowed to.

## Parts Used
- Arduino Uno
- 6 LEDs
- 6 Resistors (resistance dependent on LED used)
- 1 Sound Sensor
- Breadboard
- Wires

## Design Layout
<img src="/assets/images/music_design.png" style="width:auto; height:auto;">

## Code
### If/Else Statements Allowed

<script src="https://gist.github.com/matthew-d-freeman/ed2f64ee186fbea2048ecc384199ef13.js"></script>

*[Download Arduino Code]({{ "/assets/code/music_if.ino" | relative_url }})*
<i class="fas fa-file-pdf"></i>

---
### If/Else Statements Prohibited

<script src="https://gist.github.com/matthew-d-freeman/3a7defacda10458ea5dfb759f03a4ce1.js"></script>

*[Download Arduino Code]({{ "/assets/code/music_noif.ino" | relative_url }})*
<i class="fas fa-file-pdf"></i>

## Summary
So for my code I started practicing using arrays. I set up my pin numbers as an array and the “loudness”
parameters as an array as well. Then for my setup I initialized the sound sensors and used a for() function
in order to initialize my array of pins. I did this by having it start at 0 and count up until it is one below
the number of pins using. Then for each count it digitally wrote those pins at being outputs. I used this
same method to create a command I called turnOff() which I can use to turn all the LEDs off at once and
save me some code space. For my IF, ELSE IF, function all I did was have the parameter check the sound
sensor output and see if it was lower than the loudness array parameter I had set up earlier. This ensure
that any LED below the given loudness would turn on. At the beginning of my loop I put my turnOff()
command to reset everything and initialized how I wanted the sensor value to be read and printed in the
serial monitor. The biggest problem I had with this code is getting the loudness parameters how I liked it
and making the LEDs look less flickery. I added delays in the loop to try and cut down on the flicker and
that somewhat worked. The biggest issue here is that the sound sensor spits out data inconsistently
sometimes jumping from 0 to 700 counts in a single second. I assume this is just due to the quality of the
microphone used. I had experimented with averaging a set amount of incoming signals and using that
average as my parameter against the loudness however the result didn’t change the outcome much so I
decided to scrap it.

---

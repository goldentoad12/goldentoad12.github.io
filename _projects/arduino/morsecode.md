---
title: "Morse Code Name"
date: 2024-09-18
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
For this project, my professor wanted us to take the knowledge that we had gained from learning to blink an LED light and turn that into one of the first forms of digital communication, morse code. To do this, I would need to code the LED to blink for different amounts of time to represent dots and dashes from there I would just need to have each letter preform its series of dots and dashes to make my name.

## Parts Used
- Arduino Uno
- 1 LED
- 1 Resistor (resistance dependent on LED used)
- Breadboard
- Wires

## Design Layout
<img src="/assets/images/morse_code_design.png" style="width:auto; height:auto;">

## Code
<script src="https://gist.github.com/matthew-d-freeman/15df3237d0ae0f2dcaad675deadbf197.js"></script>

*[Download Arduino Code]({{ "/assets/code/morse_code.ino" | relative_url }})*
<i class="fas fa-file-pdf"></i>

## Summary
For this project I didn't want to just make it functional for my name but for any word. To do this I started to build my own functions so that I could make this easier. I started by creating a dot and dash function that would turn on my LED for a specific amount of time to represent a dot and dash. I also made sure to add time delays inbetween so that it woud flow more naturally and make it more recognizable. The timings for each are controlled by integers i have at the top of the code so that it would be easier to change for the design phase. After I had the dot and dashes functions down, I then created a function for each letter that would just be a series of dots and dashes to represent one letter. From here, I just used each letters function followed by a brief delay so the letters wouldn't overlap to display my name in morse code.

---

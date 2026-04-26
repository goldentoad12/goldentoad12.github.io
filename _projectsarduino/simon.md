---
title: "Simon Says Game"
date: 2024-09-16
layout: single
classes: narrow
---

<!--more-->

## Overview
For my first coding assignment for my arduino class, my professor wanted us to design a simple game using a button and an led that would allow us to test for human reaction times. To do this I would have to code an LED to turn on, turnoff, and then wait for a button press to confirm when the person saw the LED turn off. While this is happening I would need the system to count the amount of time between when the LED turned off and when the button was pressed.

## Parts Used
- Arduino Uno
- 1 LED
- 1 Resistor (resistance dependent on LED used)
- 1 Button
- Breadboard
- Wires

## Design Layout
<img src="/images/simon_game_design.png" style="width:600px; height:auto;">

## Code
<script src="https://gist.github.com/matthew-d-freeman/5c2e668786754ca06523300da692564c.js"></script>

*[Download Arduino Code]({{ "/assets/code/simon_game.ino" | relative_url }})*

## Summary
The first part of my code is initializing the different integers that I want to use specifically the led, button, start time, end time, and reaction time, as well as creating a timer and a reset timer that the game clock can be based on. Next I did my void setup where I defined the pins the button and led will be at. Furthermore I initialized the button as high so that when I press it there can be a detectable state of the buttons signal being lowered. Lastly in my setup I began the serial monitor in order to have a readout written there later on. In my loop I started by initializing the led as high for a delayed amount of time then to turn it low and start a timer. I then sent up a while command to hold the code there as long as my button remained in a high signal state. When the button was pressed and the signal was set to a low state, the timer would end and the time taken between the led turning off and the button being pressed would be calculated. The result of this calculation would then be printed in the serial monitor and the delay timer would begin before the loop would continue. 

### My Takeaway Thoughts
I think the code is as memory efficient as it could be but there are some changes to the game I would make to have it work better. Firstly, I would want to make a way so that the delay time of the led being on is more randomized and not a single time each time so that the player cant start to guess when to press it. This could be done by using a looping equation that could change the time for each game and if the number got to high reset it. Also with the beginning of the game I would put in a while command for an initial button press that way I can control when the game starts instead of having it automatically run as soon as the device is powered. 

-Footnote: My teaher showed me the random fucntion after I turned this in so that would've been helpful sooner.

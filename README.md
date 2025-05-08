https://avisofthestars.github.io/BAE305-SP25-Pinball/

Welcome to the BAE305-SP25-Pinball wiki!

# Pinball Machine Project
* By: Philip Caldbeck, Benjamin Lin, McKenzie Pickard, Avis Chen
* 25 April 2025

# Summary
For our BAE 305 final project, our group designed and built a functional pinball machine that delivers an arcade-style game experience through the integration of mechanical design, electronics, and programming. A key feature is its Arduino-controlled scoring system, which provides real-time visual feedback via LEDs and an LCD displaying scores and animations. The machine also includes interactive elements such as sensors that detect ball hits, sound effects, and animated score tracking. Players score points by skillfully using the ramps to reach strategically positioned targets on the playfield.

The machine's structure features a durable and accurate steel base, precisely cut using a waterjet. To enable custom design and seamless integration, components like the ramps, ball goals, and decorative elements were 3D printed. Our build process followed a staged approach: constructing the frame, assembling the electronic components, and programming the system. By implementing Scrum principles with weekly goals and consistent team communication, we effectively managed our workflow, promoting organization and efficiency. This project not only allowed us to delve into creative mechanical design and coding but also underscored the significance of collaboration and planning in engineering.

## Materials

### Approximate Bill of Materials w/ Links

| Part                          | Quantity | Price per Order | Purchase Link |
|-------------------------------|----------|------------------|----------------|
| Arduino Nano                  | 1x       | $2.76           | [AliExpress](https://www.aliexpress.com/item/3256806880365712.html) |
| 10pc 12V→5V Buck Converters   | 1x       | $3.69           | [AliExpress](https://www.aliexpress.com/item/3256806041034057.html) |
| 10pc TIP31 Transistors        | 1x       | $2.19           | [AliExpress](https://www.aliexpress.com/ssr/300000512/BundleDeals2?productIds=1005006003833419:12000035337625337) |
| 10pc Diodes (>2A Rating)      | 1x       | $0.91           | [AliExpress](https://www.aliexpress.com/item/3256801365779334.html) |
| Arduino Nano Terminal Adapter| 1x       | $1.41           | [AliExpress](https://www.aliexpress.com/item/3256806287053970.html) |
| 10pc DC Power Jack Socket     | 1x       | $0.92           | [AliExpress](https://www.aliexpress.com/item/2255801020080942.html) |
| 12V, 120V, 5A DC Power Supply | 1x       | $7.29           | [AliExpress](https://www.aliexpress.com/item/3256805577151044.html) |
| 12V 40mmx40mm Cooling Fan     | 1x       | $2.08           | [AliExpress](https://www.aliexpress.com/item/3256806226799133.html) |
| Solenoid (Baomain)            | 2x       | $7.49           | [Amazon](https://www.amazon.com/dp/B01K41EZAU) |
| 12mm Momentary Switch         | 3x       | $0.75           | [SparkFun](https://www.sparkfun.com/momentary-pushbutton-switch-12mm-square.html) |
| Analog Line Sensor            | 5x       | $3.95           | [SparkFun](https://www.sparkfun.com/sparkfun-redbot-sensor-line-follower.html) |
| LCD Display (HD44780)         | 1x       | $22.95          | [SparkFun](https://www.sparkfun.com/sparkfun-basic-16x2-character-lcd-white-on-black-5v-with-headers.html) |
| Piezo Buzzer                  | 1x       | $2.50           | [SparkFun](https://www.sparkfun.com/mini-speaker-pc-mount-12mm-2-048khz.html) |
| PLA Filament Spool (1kg)      | 1x       | $19.99          | [Bambu Lab](https://us.store.bambulab.com/products/pla-basic-filament?variant=564681938135969792) |
| PETG-HF Filament Spool (1kg)      | 1x       | $19.99          | [Bambu Lab](https://us.store.bambulab.com/products/petg-hf) |
| 4'x 8'x 16ga A36 Mild Steel Sheet (~50% used)     | 1x       | $35          | [Castlen Steel](https://www.castlensteel.com/steel-sales/) |
| **TOTAL**                     |          | **$135.67**       |                |


### Outer Frame
* Steel Sheets
* Spray paint
* Welder with TIG capability
* Angle grinder, C-clamps, Hammer, Drill, Tape Measure, Speed square

### Main Board
* 1x Arduino Nano, $2.76 ([Aliexpress](https://www.aliexpress.com/item/3256806880365712.html?spm=a2g0o.order_detail.order_detail_item.5.5037f19cWlZxUH))
* 22AWG wires, various colors
* Soldering iron
* Solder
* 1x 10pc 12V to 5V DC-DC Buck Converter, $3.69 ([Aliexpress](https://www.aliexpress.com/item/3256806041034057.html?spm=a2g0o.order_list.order_list_main.71.18301802Dvh7V2))
* 1x 10pc TIP31 Transistors, $2.19 ([Aliexpress](https://www.aliexpress.com/ssr/300000512/BundleDeals2?spm=a2g0o.productlist.main.3.583246d1SWqy0Q&productIds=1005006003833419:12000035337625337&pha_manifest=ssr&_immersiveMode=true&disableNav=YES&sourceName=SEARCHProduct&utparam-url=scene%3Asearch%7Cquery_from%3A))
* 1x 10pc Diodes (>2A Rating), $0.91 ([Aliexpress](https://www.aliexpress.com/item/3256801365779334.html?spm=a2g0o.order_list.order_list_main.23.18301802Dvh7V2))
* 1x Arduino Nano Terminal Adapter, $1.41 ([Aliexpress](https://www.aliexpress.com/item/3256806287053970.html?spm=a2g0o.order_list.order_list_main.5.18301802Dvh7V2))
* 1x 10pc DC Power Jack Socket, $0.92 ([Aliexpress](https://www.aliexpress.com/item/2255801020080942.html?spm=a2g0o.order_list.order_list_main.41.18301802Dvh7V2))
* 1x 12V, 120V, 5A DC Power Supply $7.29 ([Aliexpress](https://www.aliexpress.com/item/3256805577151044.html?spm=a2g0o.order_list.order_list_main.29.18301802Dvh7V2))
* 1x 12V 40mmx40mm Cooling Fan, $2.08 ([Aliexpress](https://www.aliexpress.com/item/3256806226799133.html?spm=a2g0o.order_list.order_list_main.35.18301802Dvh7V2))

### Flippers
* 2x Solenoid, $7.49 ([Amazon](https://www.amazon.com/Baomain-Solenoid-Electromagnet-JF-0530B-PushPull/dp/B01K41EZAU?crid=3V862GJTXIGOC&dib=eyJ2IjoiMSJ9.PhWsRJuGcqDXdnf3y8mReZX4OzFpVJ3_mN0UpAVy8ZS-jNmjJ5wvMSO84XtREGn7ZDcKxiitaeowovePXOw1c7ySwQ2W9MacKjCUlaEhgvSs4n7roRIeSUHxlwxFgTHl8icV99bxXnj7xIqxdhNEiNYN_djadGVeTW4x5wyNpG5SU6N7doWqhPnd3-XVe3mkqptmC5JyCekhmyCq-GMMH0W4HlDzU1RgZteh3mdhJbE.-ebBTXS2XjM2xYGlG6pJK-TXOX62ojhBnXoEjbNNl1o&dib_tag=se&keywords=baomain+solenoid&qid=1745600158&sprefix=baomain+solenoi%2Caps%2C93&sr=8-1))
* 2x 12mm Momentary Switch, $0.75 ([COM-09190 from Sparkfun](https://www.sparkfun.com/momentary-pushbutton-switch-12mm-square.html))

### Board obstacles
* 5x Analog line sensor, $3.95 ([SEN-11769 from Sparkfun](https://www.sparkfun.com/sparkfun-redbot-sensor-line-follower.html))
* 3D Printer
* 1x 1kg PLA Filament, $19.99 ([Jade White PLA from Bambu Lab](https://us.store.bambulab.com/products/pla-basic-filament?variant=564681938135969792))
* 1x 1kg PETG-HF Filament, $19.99 ([White PETG-HF from Bambu Lab](https://us.store.bambulab.com/products/petg-hf))
* Acrylic paint and paintbrush

### Scoreboard
* 1x LCD display $22.95 (HD44780 standard controls) ([LCD-18160
 from Sparkfun](https://www.sparkfun.com/sparkfun-basic-16x2-character-lcd-white-on-black-5v-with-headers.html))
* 3D printed housing
* 1x 12mm Momentary Switch Reset Button, $0.75 ([COM-09190 from Sparkfun](https://www.sparkfun.com/momentary-pushbutton-switch-12mm-square.html))
* 1x Piezo buzzer, $2.50 ([COM-07950 from Sparkfun](https://www.sparkfun.com/mini-speaker-pc-mount-12mm-2-048khz.html))

# Design Description

## Overview

Our pinball machine was designed to be an open-source, modular system. The goal is to use affordable electrical components and integrate them with one main controller. In addition, we relied heavily on our team's fabrication skills to create a robust frame with custom 3d printed and painted parts.

### Frame and Construction
The outer frame of the pinball machine was constructed using 16ga Mild Steel sheeting. A water jet was used to accurately cut steel sheets that were designed and dimensioned using a combination of Shapr3D, a 3D modeling software, and Autocad. These sections were then welded via a scratch-start TIG welding process and finished with an angle grinder fitted with an abrasive flap/sanding disc. The final frame provides a rigid body for mounting electronics, flippers, and obstacles.

### Electronics
The main microcontroller is an Arduino Nano. The nano is mounted to a terminal expansion board for ease of wiring and component testing. Our power is supplied by a 12V, 5A, DC power supply. The power is then regulated to 5V with a buck converters to power the Arduino, sensors, and sensitive electronics.

Our flippers are controlled using 12V solenoids which are actuated through TIP31 NPN transistors with diodes across the solenoids to protect against back EMF. Momentary buttons with 3d printed cases are on each side of the machine serve as flipper inputs. This system also includes a small cooling fan to dissipate heat generated, especially through high-current components.

### Sensors and Obstacles
The main field includes 3D-printed obstacle structures. The score and lives are monitored using analog line-following sensors positioned at precise locations for the ball passing through. These sensors then interface with the Arduino through analog pins.

### Scoreboard and Feedback
A 16x2 LCD display (HD44780-compatible) is used to display the score and lives. This is also driven by the Arduino. In addition, a piezo buzzer provides auditory feedback for events like scoring. In addition, a reset button will clear the scoreboard and replenish lives.

### Fabrication and Enclosure
Obstacles and the scoreboard housing were fabricated using a 3D printer with PLA and PETG filament. The top glass was made using an acrylic sheet and laser cut to fit the frame.

## Additional Resources

### 3D Model
Below is a link to the 3D model generated using Shapr3D software!

[Pinball 3D Model](https://collaborate.shapr3d.com/v/s5tUmyA981-OB2NHkjXI-?intent=share)

### Full Wiring Schematic

![](https://github.com/AvisOfTheStars/BAE305-SP25-Pinball/blob/ed3d7ba0979aca78b3c80efc03306ad2f4c2cc1e/Full%20Wiring%20Schematic.png)

_**Figure 1:** Our full wiring schematic is as follows. Components like the power supply or line sensors are simplified to their inputs and outputs as regarding the Arduino._

For the wiring part of our project, we decided to make the schematic on EasyEDA and draw it with regards to the Arduino Nano. This way, it is straightforward to see where each component should be wired. This also makes diagnosing problems with the integration of the system easier to pinpoint.

### Code

The code for our project is written in C++ and compiled through the Arduino IDE. The full .ino file can be found in our GitHub repository [here](https://github.com/AvisOfTheStars/BAE305-SP25-Pinball/blob/main/FullCode/Test.ino).

The timing of devices such as LEDs and piezo speakers are typically controlled with delays when writing code for an Arduino device. This, however, would render the pinball machine inoperable. A simplified flowchart representing this problem is shown below.  

![](https://github.com/AvisOfTheStars/BAE305-SP25-Pinball/blob/main/PinballNonfunctionalCodeFlowchart.png)

_Figure X. Simplified flowchart of non-functional code that uses delays to control audio-visual output._

Following the flowchart to the bottom, it can be seen that any time a goal sensor is tripped the machine must wait for the speaker and the lights to finish celebrating the goal before the code can advance. This causes the machine to completely freeze whenever a goal is scored, locking the flippers in place for over a second and often allowing the ball to roll to the bottom of the machine and leave the playing field. Needless to say, this created an extremely unsatisfying playing experience for the user where every successful goal also meant losing the game. 

To address this issue, our code utilizes a delta time system that coordinates the operation of multiple time-sensitive components without pausing. Instead of using delays, this system continuously monitors the current time and utilizes tracking variables to switch the state of components at the start and end of timed intervals. 

To illustrate this, take the operation of a blinking LED as an example. With delays, the code would look similar to this:

``` c++
  // Flash an LED  
  for (int i = 0; i < 5; i++) {
    digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED on
    delay(100);                      // Wait for a 1/10 second
    digitalWrite(LED_BUILTIN, LOW);   // Turn the LED off by making the voltage LOW
    delay(100);                      // Wait for 1/10 second
  }
  // By the end of all four blinks, the code has been stuck here for 1 full second
  }
```

In a delta time system, the code would instead look like this:

``` c++
void loop() {
  currentMillis = millis(); // Store the current time to reference with "last activation" times

  // If the LED has not completed its blinks, continue to blink
  if (activeLED) {
    ledBlink();
  }
  else { // Otherwise, turn it off
    digitalWrite(ledPin, LOW);
  }
}

int onScore(int goalID) {
  // Resets and enables the operation of the speaker and LED
  activeLED = 1;
  numBlinks = 0;
}

int ledBlink() {
  int timeSinceBlink = currentMillis - previousMillisLED; 
  
  // If a long time has passed, deactivate LED
  if (numBlinks >= maxBlinks) {
    activeLED = 0;
    ledState = LOW;
  }
  
  // If the button has been recently pushed, allow the LED to blink
  if (activeLED) {
    //Blink the LED according to the LED speed (higher combo = faster blinks)
    if (timeSinceBlink >= blinkSpeed) { // When the current interval exceeds its duration, flip the state of the LED
      previousMillisLED = currentMillis;
      if (ledState == LOW) {
        ledState = HIGH;
      }
      else {
        ledState = LOW;
        numBlinks++; // Switching the LED from on to off counts as one blink
      }
    }
  }

  digitalWrite(ledPin, ledState); // Output the updated state of the LED
}
```

This code relies on three main globally declared tracking variables to work. The first is activeLED, which controls whether the code evaluating and controlling the LED should be run at all. The scoring system--among other responsibilities--sets activeLED to 1 (boolean true) whenever the ball passes through a goal. Once all blinks are complete, the function controlling LED operation sets activeLED to false, allowing the code to skip checking the state of the LED and save a small amount of computing power.

The remaining variables, timeSinceBlink and previousMillisLED, work in tandem to make the LED blink. Any time the LED switches states, the current time is saved to timeSinceBlink. This is compared to the current time in every loop with the resulting value being stored in previousMillisLED. When previousMillisLED is larger than the duration of one half-blink, the state of the LED flips (which updates timeSinceBlink to be the now-current time).  

The basic structure of this code (check current time, compare the current time when the last update occurred, change state if the difference is greater than the operating interval) is repeated for all other non-instantaneous systems in the machine. In effect, this removes every instance of a delay that would freeze the machine, allowing for simultaneous operation of every system. 

The only system that does not use delta timing is the flippers, which never required the a delay to operate. Instead, the code controlling the flippers opts to pass the state of the side buttons directly through to the flippers' solenoids, a sleek and elegant solution that operates at instant speed.

A simplified flowchart of our final code is shown below.

**(To do: make a flowchart for the final code)**



# Testing Description

# Design Decision Discussion

## Overview

Our design focused on simplicity, modularity, and accessibility to allow room for adapting or altering for future iterations. These decisions were made to balance the cost, integration, and life-time of parts. We prioritized parts that are easy to source and code for quick integration.

### Microcontroller
We selected the Arduino Nano due to its affordability, small form-factor, easy programming, large library database, and IO port selection. Its small footprint allowed us to integrate it into a small area and the terminal adapter board simplified wiring and testing. We also considered using ESP 32 and STM 32 boards, but they are harder to integrate and more powerful and expensive than needed. Overall, the Arduino Nano provided sufficient I/O and performance.

### Power
The 12V 5A power supply was chosen to meet the current and wattage demands of solenoids and other components. We also included some overhead for leeway in case of future additions or more powerful component requirements. Then, we used buck converters to provide a 5V source for sensitive electronics and Arduino powering. This power design allows us to bypass using the Arduino's power regulator to lower heat production, and also keeps our solenoids using a different power rail for higher force capability.

### Flippers 
We selected 12V solenoids to deliver enough force for flipper movement and paired them with diodes to prevent back-EMF damage. Since the solenoids cannot be directly powered by our Arduino, we used TIP31 transistors to switch them on and off reliably. With approximately 50 gain, we can use a low output current from the Arduino to reduce wear.

### Fabrication
We utilized 3D printing, plasma cutting, and laser cutting to produce our custom parts and enclosures with close tolerances. All printable designs were created to be modular and easily replaceable. The decision to use steel for the frame rather than wood or plastic was for both aesthetics, high stability, and easy mounting. The acrylic top sheet serves as a dust cover and viewing window without the fragility of glass. 

# Test Results Discussion

## Overview

We were able to test all of our components out individually during our open lab time in the weeks leading to the final project due date. While they were not completely integrated with the code and soldered permanently to the system, we verified that the components were functional on their own.

### Solenoid

After trial and error, we were able to find a working solenoid system. We used a TIP31 transistor and a 220ohm resistor hooked up to ~5V signal (providing approximately 20mA). Then we were able to achieve a high gain of ~50, leading to our solenoids functioning at roughly 1A and 12V. This is the ideal input for the specific solenoids that we are using to achieve high power and response time. This was a learning moment for the group as we misused a PNP transistor and ran too much current through it. While the loss of a resistor is negligible, it helps teach some fundamentals in project planning to prevent waste and safety concerns.

### LCD

The LCD screen was dialed in using a potentiometer to differentiate the backlight from the pixels. We also created code for displaying the user's score and lives. This works in tandem with our sensors to create an interactive experience. Overall, this was not a difficult component to test due to the high amount of support for this kind of display.

### Line-Follower Sensors

The Line-Follower Sensors were utilized as a backup instead of the ideal laser module systems. Since our laser modules never arrived, we pivoted to a different kind of sensor. This raised some new challenges as the line-follower modules have a small working distance. This meant we had to change our obstacles to funnel our pinball through a choke point to consistently and accurately be measured. Overall, our group was able to adapt well after some calibration and lots of iterative coding.

# Testing Results

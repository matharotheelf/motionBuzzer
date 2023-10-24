<!-- ABOUT THE PROJECT -->
## About The Project

Control the sounds of a buzzer using the motions of your hand. Use the timing of handmovents infront of a motion sensor to control the buzzer's tone.



### Built With

* [Arduino](https://www.arduino.cc/)

<!-- GETTING STARTED -->
## Getting Started

### Prerequisites

The hardware needed for this project are the following:

1. Arduino Microcontroller
2. Computer with Arduino installed
3. 4 LED lights
4. 4 ~220 Ohm resistors
5. Passive Buzzer
6, PIR Motion Sensor

### Installation

1. Install the [Arduino IDE](https://docs.arduino.cc/software/ide-v1)

2. Clone this repo

3. Open the file `overtoneBuzzer.ino` in the IDE.

4. Upload the code to a connected Arduino.

### Hardware Setup

The circuit Diagram for the project is as follows:

![Circuit Diagram](https://github.com/matharotheelf/motionBuzzer/assets/44533664/599d5c55-f502-40fb-a9c2-2af026d87633)

## Usage

To use:

1. Trigger the motion sensor by moving your hand to start the timer.
3. Trigger the motion sensor a second to stop the timer.
4. The buzzer will create a frequency corresponding to the time elapsed and the lights will cycle with the given duration.
5. Trigger the motion sensor again to restart.

![Motionbuzzer](https://github.com/matharotheelf/motionBuzzer/assets/44533664/113ff538-b06a-46be-a78b-18769873dfec)


## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

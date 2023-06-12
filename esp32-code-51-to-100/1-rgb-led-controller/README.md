# RGB Led Controller
## Introduction
This repository stores the files of the RGB Led Controller project - a simple but incredible fun DIY challenge.
Some time ago I found a guy who used his ESP32 board to control a led remotely. In truth, his goal was to explain how to build a socket web server using ESP32 and MicroPython, and he found that making it to blink a led was a great way to demonstrate some network concepts.

After reading his article, I decided to give it a try. However, I would like to control a RGB led instead of a simple led. In this case, there are three output signals to turn on and off. The first step to accomplish my desire was to make the webpage. ESP32 works as a server and stores the page. Everytime it gets a connection, it returns a response that contains the page.

The website has tree buttons. Each one turns on and off the red, green and blue lights. It's possible to turn on more than one light simultaneously. If the light is off, the button shows OFF. Otherwise it shows ON. I used nothing more than HTML and CSS to build it and Bootstrap 5 to make the website mobile friendly.

### Desktop view
![1](https://user-images.githubusercontent.com/131505597/233798508-aef03380-8455-446d-8ce0-6c90d383ccd4.png)

### Cellphone view
![2](https://user-images.githubusercontent.com/131505597/233798535-6c606305-94cb-4922-acc2-1866f3b6497d.png)

## Files
All code is splitted into two files: boot.py and main.py. The first one runs at first and only once when the board is turned on or rebooted. It sets the board to connect to the local wi-fi as well as turns the digital pins 21, 22, and 23 as OUTPUT.

Take a look at this file. There are two special variables here: ssid and password. **Modify them to store your network name and password before uploading the code to ESP32.**

The second file - main.py - contains the code that runs while the board is powered. It sets up the socket server and keep it listening for connections. When it gets a request, it returns the page and closes the communication. Now you may be wondering: what is the address of the website stored in ESP32? Well, the boot.py file prints a log that shows the website address, see the example below:

![3](https://user-images.githubusercontent.com/131505597/233799457-6acb1d5e-a43d-4ea3-bbaa-600150158b6d.png)

In this case, I pluged the ESP32 board to my computer and ran the code in the Thonny IDE - probably the best IDE to work with MicroPython (I highly recommend you use it on your own projects). As you can see in the first adn second images, 192.168.0.13 is the address I typed on my browser.

## Hardware

You just need four things to build your system. They are:
- ESP32
- Breadboard
- RGB led
- Four jumper wires male to male

Put the RGB led and ESP32 on the breadboard. Use the wires to connect the led GND to the board GND. Also connect the red, green, and blue pins to the digital ports 21, 22, and 23 respectively.

![4](https://user-images.githubusercontent.com/131505597/233799919-7b7bf726-d50a-4a4c-aee2-0d517de2ec4d.jpg)

## Conclusion

I really hope you enjoyed this project and learned a lot. It's simple but challeging for people who just began their microcontroller learning.

Watch [my video](https://youtube.com/shorts/v2qsgdlMDTQ?feature=share) in which I show off this project.

Now that you got here, upload the code, go to the RGB Led Controller page, and have fun!

![rgb-led-controller](https://user-images.githubusercontent.com/131505597/233800681-4fbc7a30-85d6-4775-9e21-42a183c67f50.gif)

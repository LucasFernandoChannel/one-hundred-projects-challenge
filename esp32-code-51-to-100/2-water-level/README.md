# Water level
## Introduction
I own a water level sensor but used it only once. I might say this sensor didn't catch my attention for too long, so after playing with it for one hour or two, I forgot about it. But now I decided to give it another try, and today I'll show you something very interesting you can built.

This is a simple MicroPython project. You just need four things:
- Three jumper wires male to female
- Breadboard
- ESP32
- Water level sensor

Put the ESP32 board in the breadboard and use the wires to attach it to the sensor. Connect the positive and negative to the VIN and GND ports and the signal pin should go to port 33.

![1](https://user-images.githubusercontent.com/131505597/233816059-c3cacd32-b1ff-44bd-831f-abed10c8032d.jpg)

Now that everything is wired up let me explain about the code.

## Code
The code was splitted into two files: boot.py and main.py. The first file runs at first and only once. It sets up the board to be a wi-fi station and connects it to your local network. The code also sets the pin 33 to read analog signals. That's crucial for this project because our sensor produces analog signals.

The second file sets the board to be a socket server. Every time someone goes to the page stored in the board, it returns the website and closes the connection. To discover what is your website address, take a look at the log (printed messages) of the boot.py - see the example below:

![2](https://user-images.githubusercontent.com/131505597/233816320-b9f3eb76-2d0c-4b12-b869-8eaa3048ba3c.png)

I connected my ESP32 to my computer and ran the boot.py file in Thonny IDE - probably the best IDE to work with MicroPython.

After uploading the files and going to your website address, you will see something like this:

![3](https://user-images.githubusercontent.com/131505597/233816499-384a0788-8600-4a01-bb89-3af12bea253a.png)

The page reloads automatically every two seconds in order to keep the card updated. As you can see after testing it, there are four different cards:
- Blue card - no danger
- Orange card - caution
- Red card - danger
- Purple card - critical

Each card has its own title, text, and color according to the water level. The greatest the level the most critical is the card and its message.

![water-level](https://user-images.githubusercontent.com/131505597/233816910-9d93c57b-214e-4082-8906-dfe09ba3a252.gif)

## Conclusion
I really hope you enjoyed and learned a lot from this project. The hardware part is easy to do, but, in my option, coding is the funniest thing (making all the commands work and debugging is very satisfying). I recorded a video showing this project working. You can watch my video [here](https://youtube.com/shorts/VO1AbaKXQ3s). Also, you are free to use and modify the code the way you think is the best.

# Project #1 - RGB LED controller
# This code is part of the challenge 100 Arduino and ESP32 projects.
# You can find more information about this initiative at https://github.com/LucasFernandoChannel/one-hundred-projects-challenge
# Created by Lucas Fernando - check my Youtube channel at https://www.youtube.com/@lucasfernandochannel

try:
    import usocket as socket
except:
    import socket

from esp import osdebug
from gc import collect
from machine import Pin
from network import WLAN, STA_IF
from time import sleep

def connectWifi(ssid, password):
    osdebug(None)
    collect()
    ledWifi = Pin(2, Pin.OUT)

    station = WLAN(STA_IF)
    station.active(True)
    station.connect(ssid, password)
    
    while (station.isconnected() == False):
        ledWifi.value(1)
        sleep(0.15)
        ledWifi.value(0)
        sleep(0.15)
        pass
        
    print("ESP32 connected to wi-fi")
    print(station.ifconfig())
    
    return None


def setUpLeds():
    redLed = Pin(21, Pin.OUT)
    greenLed = Pin(22, Pin.OUT)
    blueLed = Pin(23, Pin.OUT)
    
    redLed.value(0)
    greenLed.value(0)
    blueLed.value(0)
    
    return redLed, greenLed, blueLed
    

ssid = "YOUR_WIFI_NAME"
password = "YOUR_WIFI_PASSWORD"

connectWifi(ssid, password)
redLed, greenLed, blueLed = setUpLeds()

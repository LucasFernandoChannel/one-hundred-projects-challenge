# Created by Lucas Fernando - 22th April 2023
# Feel free to modify this code the way you want and need.

try:
    import usocket as socket
except:
    import socket

from esp import osdebug
from gc import collect
from machine import Pin, ADC
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
    

def defineSensor():
    sensor = ADC(Pin(33))
    sensor.atten(ADC.ATTN_11DB) # Full range 3.3V
    return sensor
    
    
ssid = "YOUR_WIFI_NAME"
password = "YOUR_WIFI_PASSWORD"
connectWifi(ssid, password)
sensor = defineSensor()

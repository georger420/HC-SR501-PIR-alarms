# Write your code here :-)

import board
import digitalio
import time
from adafruit_debouncer import Debouncer

led = digitalio.DigitalInOut(board.LED)
led.direction = digitalio.Direction.OUTPUT
button = digitalio.DigitalInOut(board.GP22)
button.switch_to_input(pull=digitalio.Pull.DOWN)
buzzer = digitalio.DigitalInOut(board.GP18)
buzzer.direction = digitalio.Direction.OUTPUT
pir = digitalio.DigitalInOut(board.GP28)
pir.direction = digitalio.Direction.INPUT
switch = Debouncer(button)

greenled = digitalio.DigitalInOut(board.GP15)
greenled.direction = digitalio.Direction.OUTPUT

redled = digitalio.DigitalInOut(board.GP14)
redled.direction = digitalio.Direction.OUTPUT

armed = False

def pipip():
    buzzer.value = True
    time.sleep(0.3)
    buzzer.value = False
    time.sleep(0.15)

         
        



while True:
    # print("armed:  ", armed)
    # print(button.value)
    switch.update()
    if (switch.rose):
        if (armed==False):
            armed=True
            # time.sleep(30)
        else:
            armed = False
            # time.sleep(0.5)
    if armed:
        redled.value = True
        greenled.value = False
    else:
        redled.value = False
        greenled.value = True        
    
    if (pir.value):
        led.value = True
        if armed:
            pipip()
    else:
        led.value = False
        buzzer.value = False
    # time.sleep(0.01)


"""
while True:
    switch.update()
    if switch.fell:
        print('Just released')
    if switch.rose:
        print('Just pressed')
    if switch.value:
        print('pressed')
    else:
        print('not pressed')
    time.sleep(0.5)
"""    











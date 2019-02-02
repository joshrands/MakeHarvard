# ir-test.py
# Program to test the receptive functionality of ir receivers

import RPi.GPIO as GPIO
import numpy as np
import time

# setup PIN variables
IR_LED1 = 4

GPIO.setmode(GPIO.BCM)

# setup GPIO ports



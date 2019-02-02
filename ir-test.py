# ir-test.py
# Program to test the receptive functionality of ir receivers

import RPi.GPIO as GPIO
import numpy as np
import time

GPIO.setmode(GPIO.BCM)

# setup ouput PIN variables
IR_LED1 = 4 # make this an array
GPIO.setup(IR_LED1, GPIO.OUT)

# setup input PIN variables
IR_REC1 = 21 # make this an array
GPIO.setup(IR_REC1, GPIO.IN, GPIO.PUD_DOWN)

try:
	while True:
		GPIO.output(IR_LED1, True)
		time.sleep(0.5)
		ir = GPIO.input(IR_REC1)
		print ir
		time.sleep(0.5)

    GPIO.output(IR_LED1, False)
    time.sleep(0.5)
		ir = GPIO.input(IR_REC1)
		print ir
		time.sleep(0.5)

	time.sleep(.0001)

except(KeyboardInterrupt, SystemExit):
	print("Excepted interrupt")
	GPIO.output(IR_LED1, False)
	exit
finally:
	GPIO.cleanup()




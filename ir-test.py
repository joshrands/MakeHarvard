# ir-test.py
# Program to test the receptive functionality of ir receivers

import RPi.GPIO as GPIO
import numpy as np
import time

# setup PIN variables
IR_LED1 = 4

GPIO.setmode(GPIO.BCM)

# setup GPIO ports
GPIO.setup(IR_LED1, GPIO.OUT)


try:
	while True:
		GPIO.output(IR_LED1, True)
		time.sleep(1)
                GPIO.output(IR_LED1, False)
                time.sleep(1)
	time.sleep(.0001)

except(KeyboardInterrupt, SystemExit):
	print("Excepted interrupt")
	GPIO.output(IR_LED1, False)
	exit
finally:
	GPIO.cleanup()




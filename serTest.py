import serial
import time

#ser = serial.Serial('/dev/ttyUSB0')
serSend = serial.Serial('/dev/ttyACM1')

while True:
#	print(ser.readline())
	
	time.sleep(1)
	print(serSend.write('H'.encode()))
	time.sleep(1)
	print(serSend.write('L'.encode()))



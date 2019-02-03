import serial

ser = serial.Serial('/dev/ttyUSB1')

while True:
	print(ser.readline())


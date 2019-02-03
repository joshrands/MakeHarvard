# ground PC station

import serial
import time
from helper import *

# get master and slave ports
masterPort = "/dev/ttyUSB0"#input("Enter master port: ")
slavePort = "/dev/ttyUSB1"#input("Enter slave port: ") 

master = serial.Serial(masterPort)
slave = serial.Serial(slavePort)

while True:
	# check master state
	masterData = master.readline()

	masterData = parseMaster(masterData)
	print(masterData)

	slaveSig = 0
	if (masterData == b'A_R\n'):
		print("Sending turn right signal...")	
		slaveSig = 3

	

 

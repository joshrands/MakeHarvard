# ground PC station

import serial
import time
from helper import *

x = input("Sync boards and press enter.")

# get master and slave ports
masterPort = "/dev/ttyUSB0"
#masterPort = input("Enter master port: ")
slavePort = "/dev/ttyUSB2"
#slavePort = input("Enter slave port: ") 

master = serial.Serial(masterPort)
#slave = serial.Serial(slavePort)

ir = []

# TODO: ADD SYNC

def addIR(data):
	word = data.decode()
	val = int(word[len(word) - 2])	

	print("IR Receiver: " + str(val))
	
	if (data == b'IR9_0\n' or data == b'IR9_1\n'):
		print(ir)
		# new data, clear ir table
		del ir[:]
		ir.append(val)
	else:
		ir.append(val)

while True:
	# check master state
	masterData = master.readline()

	masterData = parseMaster(masterData)
#	print(masterData)

	slaveSig = '0'

	if (masterData == b'A_L\n'):
		print("Sending turn left signal...")
		slaveSig = '1'
	elif (masterData == b'A_R\n'):
		print("Sending turn right signal...")	
		slaveSig = '3'
	elif (masterData == b'A_F\n'):
		print("Sending power forward signal...")
		slaveSig = '2'
	elif (masterData == b'A_0\n'):
		# this is IR data, run model
		print("Stop")
		slaveSig = '0'
		#addIR(masterData)
	else:
		addIR(masterData)
		slaveSig = 'f'	

	# send data
#	if (slave.write(slaveSig.encode()) > 0):
#		print("Data sent to slave.")	
#	else:
#		print("Error sending data to slave.")

	

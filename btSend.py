import bluetooth
import sys
import time
#bd_addr = "00:12:10:23:10:18" #itade address
bd_addr = "00:06:66:f2:49:7d"

port = 1
sock=bluetooth.BluetoothSocket(bluetooth.RFCOMM)
sock.connect((bd_addr, port))
print("Connected")
sock.settimeout(3.0)

for i in range(0,5):
	print (sock.send('H'.encode()))
	print("Sent data")
	time.sleep(1)
	print (sock.send('L'.encode()))
	time.sleep(1)

#sock.close()



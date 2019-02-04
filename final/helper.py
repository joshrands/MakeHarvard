# Helper functions for ground
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

import random

def irAlgorithm(ir):
	file = open("data.csv", "a")
	file.write("\n");
	
	signal = False
	for i in range(0, len(ir) - 1):
		file.write(str(ir[i]) + str(","))
		if ir[i] != 0:
			signal = True	

	# perform analytics
	leftScore = 0
	rightScore = 0

	if (not signal):
		print("No signal.")
	else:
		for i in range(0, 4):
			print(ir[i]) 
			leftScore += ir[i]
		for i in range(4, len(ir) - 1):
			print(ir[i])
			rightScore += ir[i]

	print("Right score: " + str(rightScore))
	print("Left score: " + str(leftScore))

	# write to file
	file.write(str(leftScore) + "," + str(rightScore))
	file.close()

def parseMaster(data):
	return data


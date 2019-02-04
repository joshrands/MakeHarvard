import matplotlib.pyplot as plt
import matplotlib.animation as animation
import numpy as np

# Create figure for plotting
fig = plt.figure()
ax = fig.add_subplot(1, 1, 1)
xs = []
ys = []

# This function is called periodically from FuncAnimation
def animate(i, xs, ys):
	# read from file
	file = open("data.csv", "r")
	params = file.readline()

	fileData = file.read().splitlines()
	for line in fileData:
		split = line.split(',')
		xs.append(split[0])
		ys.append(split[1])

	# Limit x and y lists to 20 items
	xs = xs[-2:]
	ys = ys[-2:]

	x = np.array(xs)
	y = np.array(ys)

	plt.bar(y, x, align='center', alpha=0.5)
	plt.xticks(y_pos, objects)
	plt.ylabel('Usage')
	plt.title('Programming language usage')
	 
	plt.show()

# Set up plot to call animate() function periodically
ani = animation.FuncAnimation(fig, animate, fargs=(xs, ys), interval=1000)
plt.show()


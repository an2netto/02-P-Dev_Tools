#!/usr/bin/env python3

import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

f = open('data.txt', 'r')
lines = f.read().splitlines()   

x = [int(n) for n in lines[0].split()]
y1 = [float(n) for n in lines[1].split()]
y2 = [float(n) for n in lines[2].split()]
y3 = [float(n) for n in lines[3].split()]
y4 = [float(n) for n in lines[4].split()]
y5 = [float(n) for n in lines[5].split()]

f.close()

plt.plot(x, y1, color='b', linestyle='--', label='-O0')
plt.plot(x, y2, color='r', linestyle='-', label='-O1')
plt.plot(x, y3, color='g', linestyle='--', label='-O2')
plt.plot(x, y4, color='c', linestyle='-', label='-O3')
plt.plot(x, y5, color='m', linestyle='-', label='-Os')

plt.title('DFT performance: O(n^2)', size=12)
plt.legend(loc='upper left')
plt.xlabel('Number of items', size=12)
plt.ylabel('Measured time, ms', size=12)

plt.savefig('plot.png')


#!/usr/bin/env python3

from integer import Integer
from time import perf_counter as pc
import matplotlib.pyplot as plt

def fib_py(n):
	if n<=1:
		return n
	else:
		return(fib_py(n-1)+fib_py(n-2)) #the provided code

def main():
	x,y = [range(30,46,1)], []
	for elt in range(16):		#finds the time taken for each c fib run by indexing upwards
		f = Integer(30+elt)
		start = pc()
		f.fib()
		end = pc()
		y.append(end-start)
	x1, y1 = [range(30,46,1)], []
	for elt in range(30,46,1):		#does the same for the python function
		start = pc()
		fib_py(elt)
		end = pc()
		y1.append(end-start)
	plt.scatter(x,y, c='b', marker='x', label='c')
	plt.scatter(x1, y1, c='r', marker='s', label='python')
	plt.legend(loc='upper left')
	plt.xlabel('Fibonacci number (n)')
	plt.ylabel('Time (s)')
	plt.savefig("test.png")
	g = Integer(47)
	print("n=47: " + g.fib())
if __name__ == '__main__':
	main()

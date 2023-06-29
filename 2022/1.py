import time
import sys
from pathlib import Path
import math

##############################################
##############################################
##############################################

def solve():
	def XOR(a, b):
		return a^b

	def C(s0, s1, ci):
		return XOR(XOR(s0, s1), ci)

	def performShift(shift, direction):
		if direction > 0: # Send font digit to back of shift
			front = shift[0]
			del shift[0]
			shift.append(front)
		else: # Send back digit to front of shift 
			last_digit = shift.pop()
			shift.insert(0, last_digit)
		

	def performTurn(shift, check, direction, i, r):
		for x in range(r):
			performShift(shift, direction)
		check[i] = C(shift[0], shift[-1], check[i])
	
	def part_a():
		shift = input()
		check = input()
		r = int(input())
		L = len(shift)
		direction = 1
		if r < 0:
			direction = -1
		r = abs(r) % L # CRUCIAL FOR SPEED

		shift = [int(i) for i in shift]
		check = [int(i) for i in check]
		
		for i in range(L):
			performTurn(shift, check, direction, i, r)
		
		for x in range(len(check)):
			print(check[x], end="")
		print()
			
			

	def part_c():
		print(math.comb(pow(2, 23),2))

	part_a ()
	# part_c()

##############################################
##############################################
##############################################

def usingFiles():
	# Creates files if they do not exist
	path = Path('../input.txt')
	if not path.is_file():
		file = open("../input.txt", "w")
		file.write("\n") # Must write empty space to avoid EOF error
		file.close()
	
	sys.stdin = open("../input.txt", "r")
	sys.stdout = open("../output.txt", "w")

	start = time.time()

	solve()

	end = time.time()

	print("\ntime taken: " + str(end - start) + " seconds")

	sys.stdin.close()
	sys.stdout.close()

def usingTerminal():
	solve()

if __name__ == "__main__":
	usingFiles()
	# usingTerminal()




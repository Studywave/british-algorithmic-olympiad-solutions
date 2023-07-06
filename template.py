import time
import sys
import math

##############################################
##############################################
##############################################

def usingFiles():    
    # WARNING: Must create the files yourself
    # Adjust the path depending on where the input/output files are
	sys.stdin = open("../input.txt", "r")
	sys.stdout = open("../output.txt", "w")

	start = time.time()

	solve()

	end = time.time()

	print("\ntime taken: " + str(end - start))

	sys.stdin.close()
	sys.stdout.close()

def usingTerminal():
    solve()

if __name__ == "__main__":
    # usingFiles()
    usingTerminal()

##############################################
##############################################
##############################################

def part_a():
	pass

def solve():
	part_a()




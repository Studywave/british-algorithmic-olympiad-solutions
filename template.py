import time
import sys
from pathlib import Path

##############################################
##############################################
##############################################

def solve():
	def part_a():
		pass

	part_a()

##############################################
##############################################
##############################################


def usingFiles():
    # Creates files if they do not exist
	path = Path('../input.txt')
	if not path.is_file():
		file = open("../input.txt", "w")
		file.close()
    
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
    usingFiles()
    # usingTerminal()




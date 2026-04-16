# ******************************************************************************
# Author:      Nathan Lo
# Alpha:       m283852
# Title:       Makefile
# Description: Compiles both the practice and homework executables.
# Date:        2026-04-12
# ******************************************************************************

# Compiles the practice program
prac: prac.cpp
	g++ prac.cpp -o prac

# Compiles the main homework program 
hw: hw.cpp ll.cpp ll.h
	g++ hw.cpp ll.cpp -o hw

############### DON'T TOUCH BELOW #######################
runprac: prac
	@valgrind ./prac 2> out; python3 val.py
run: hw
	@valgrind ./hw 2> out; python3 val.py
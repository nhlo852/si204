# ******************************************************************************
# Author:      Nathan Lo
# Alpha:       m283852
# Title:       Makefile
# Description: Compiles all four parts of Lab 11
# Date:        2026-04-13
# ******************************************************************************

part1: part1.cpp list.cpp list.h
	g++ part1.cpp list.cpp -o part1

part2: part2.cpp list.cpp list.h
	g++ part2.cpp list.cpp -o part2

part3: part3.cpp list.cpp list.h
	g++ part3.cpp list.cpp -o part3

part4: part4.cpp list.cpp list.h
	g++ part4.cpp list.cpp -o part4

############# DON'T TOUCH BELOW ################
run%: part%
	@valgrind ./part$* 2> out; python3 val.py
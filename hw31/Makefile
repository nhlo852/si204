hw: hw.cpp list.cpp list.h
	g++ hw.cpp list.cpp -o hw
	
prac: prac.cpp
	g++ prac.cpp -o prac
	
############# DON'T TOUCH BELOW #########################3
run: hw
	@valgrind ./hw 2> out; python3 val.py 
runprac: prac
	@valgrind ./prac 2> out; python3 val.py
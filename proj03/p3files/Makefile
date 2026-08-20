part1: part1.cpp board.cpp board.h
	g++ part1.cpp board.cpp -o part1

part2: part2.cpp board.cpp board.h
	g++ part2.cpp board.cpp -o part2

part3: part3.cpp board.cpp board.h easycurses.cpp easycurses.h
	g++ part3.cpp board.cpp easycurses.cpp -o part3 -lcurses

part4: part4.cpp board.cpp board.h easycurses.cpp easycurses.h
	g++ part4.cpp board.cpp easycurses.cpp -o part4 -lcurses

part5: part5.cpp board.cpp board.h easycurses.cpp easycurses.h
	g++ part5.cpp board.cpp easycurses.cpp -o part5 -lcurses

part6: part6.cpp board.cpp board.h easycurses.cpp easycurses.h
	g++ part6.cpp board.cpp easycurses.cpp -o part6 -lcurses

################## DON'T TOUCH BELOW ##################
run1: part1
	@valgrind ./part1 2> out; python3 val.py 
run2: part2
	@valgrind ./part2 2> out; python3 val.py 
run3: part3
	@valgrind ./part3 2> out; python3 val.py 
run4: part4
	@test -f part4 && echo "part4: Code compiled successfully" 
run5: part5
	@test -f part5 && echo "part5: Code compiled successfully" 
run6: part6
	@test -f part6 && echo "part6: Code compiled successfully"
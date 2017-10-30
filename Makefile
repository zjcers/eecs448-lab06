#Zane J Cersovsky 2017

prog: main.o Tests.o
	g++ -g -Wall -std=c++11 main.o LinkedListOfInts.o Tests.o -o prog


%.o: %.cpp 
	g++ -g -Wall -std=c++11 -c $<

#DON'T delete LinkedList.o!
clean:
	rm main.o *.*~ prog Tests.o

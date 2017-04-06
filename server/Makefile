all: server
server: server.o query.o
	g++ -std=c++11 server.o query.o -o server
	
server.o: server.cpp 
	g++ -std=c++11 -g -c server.cpp 

query.o: query.cpp query.h 
	g++ -std=c++11 -g -c query.cpp

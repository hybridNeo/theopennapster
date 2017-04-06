all: server
server: server.o query.o com.o
	g++ -std=c++11 -lboost_system -lboost_thread server.o query.o com.o -o server
	
server.o: server.cpp 
	g++ -std=c++11 -g -c server.cpp 

query.o: query.cpp query.h 
	g++ -std=c++11 -g -c query.cpp

com.o : com.cpp com.h

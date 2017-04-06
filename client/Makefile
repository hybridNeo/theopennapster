all: client
client: client.o com.o
	g++ -std=c++11 client.o com.o -o client

client.o: client.cpp
	g++ -std=c++11 -g -c client.cpp

com.o: com.h com.cpp
	g++ -std=c++11 -g -c com.cpp

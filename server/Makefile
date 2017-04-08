all: server
server: server.o query.o com.o
	mkdir -p ./out
	g++ -std=c++11  out/server.o out/query.o out/com.o -o out/server -lboost_system
	
server.o: server.cpp
	mkdir -p ./out 
	g++ -std=c++11 -g -c server.cpp -o ./out/server.o

query.o: query.cpp query.h 
	mkdir -p ./out
	g++ -std=c++11 -g -c query.cpp -o ./out/query.o

com.o : com.cpp com.h
	mkdir -p ./out
	g++ -std=c++11 -g -c com.cpp -o ./out/com.o

clean:
	rm -rf ./out

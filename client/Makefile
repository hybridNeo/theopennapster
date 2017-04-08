all: client
client: client.o com.o
	mkdir -p ./out
	g++ -std=c++11 ./out/client.o ./out/com.o -o out/client

client.o: client.cpp
	mkdir -p ./out
	g++ -std=c++11 -g -c client.cpp -o ./out/client.o

com.o: com.h com.cpp
	mkdir -p ./out
	g++ -std=c++11 -g -c com.cpp -o ./out/com.o

clean:
	rm -rf ./out

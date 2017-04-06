#include <iostream>
#include <string>
#include "com.h"
using namespace std;

void get_input(string& str, char **argv, int argc){
	for(int i = 1; i < argc ; ++i){
		str.append(argv[i]);
		str.append(" ");
	}
}

int main(int argc, char **argv){
	if(argc < 2){
		cout << "[INVALID ARGUMENTS ]Enter message" << endl;
		return 0;	
	}

	string input_str;
	get_input(input_str, argv, argc);
	cout << "[INPUT]"<< input_str << endl;
	send_msg(input_str);
}

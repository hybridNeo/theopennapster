#include "query.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

string fetch_file_path(string filename){
	cout << "STUB:" << "Looking for file " << filename << endl;
	string complete_name = "/home/rahulmahadev/";
	complete_name.append(filename);
	cout << "[FILE FINDER]" << "Finding file : " << complete_name << endl;
	return complete_name;
}


string slurp(ifstream& in){
	std::stringstream sstr;
	sstr << in.rdbuf();
	std::cout << "this is the string " << sstr.str() << std::endl;
	return sstr.str();
}

std::string get_file_contents(std::string filename)
{

	std::ifstream t("/home/rahulmahadev/test.txt");
	t.seekg(0, std::ios::end);
	size_t size = t.tellg();
	std::string buffer(size, ' ');
	t.seekg(0);
	t.read(&buffer[0], size); 
	return buffer;
}

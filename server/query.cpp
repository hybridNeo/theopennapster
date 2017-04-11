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

string fetch_file_content(string file_path){

	cout << "[STUB]" << "Fetching file " << file_path << endl;
	std::ifstream ifs(file_path);
	std::string content((std::istreambuf_iterator<char>(ifs) ),(std::istreambuf_iterator<char>()));
	cout << "The content is " << content << endl;
	return content;
}

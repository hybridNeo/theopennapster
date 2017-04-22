#include "query.h"
#include <iostream>
#include <fstream>
#include <boost/filesystem.hpp>
#include <sstream>
using namespace std;

string fetch_file_path(string filename){
	cout << "[SERVER]:" << "Looking for file " << filename << endl;
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

int get_file_contents(std::string filename, std::string& contents)
{
	boost::filesystem::path myfile(filename);
	if( !boost::filesystem::exists(myfile) ){
		std::cout <<"[SERVER] Unable to find requested file." << myfile << std:: endl; 
		return 0;
        // what do you want to do if the file doesn't exist 
    }
	std::ifstream t(filename);
	t.seekg(0, std::ios::end);
	size_t size = t.tellg();
	std::string buffer(size, ' ');
	t.seekg(0);
	t.read(&buffer[0], size); 
	contents = buffer;
	return size;
}

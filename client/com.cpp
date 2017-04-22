#include <iostream>
#include "com.h"
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <fstream>
#include <string>
using boost::asio::ip::tcp;

void create_file(std::string data, std::string file_path){
	std::ofstream out(file_path);
	out << data;
	out.close();
}

int send_msg(std::string message){

	std::string ip = "127.0.0.1";
	send_to_endpoint(ip, SERVER_PORT , message);
}

int send_to_endpoint(std::string& serv_ip , int serv_port, std::string& message){
	std::cout << "[CLIENT] Sending message to the server -- " << message << std::endl;
	boost::asio::io_service io_service;
	boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string(serv_ip), serv_port);
    
	try{
		boost::asio::ip::tcp::socket socket(io_service);
		socket.connect(endpoint);

		boost::array<char, 128> buf;
  	    std::copy(message.begin(),message.end(),buf.begin());
	    boost::system::error_code error;
	    socket.write_some(boost::asio::buffer(buf, message.size() ), error);	
		socket.read_some(boost::asio::buffer(buf), error);
		std::cout << "[CLIENT] Downloading file: " << message << std::endl;
		if(!strcmp(buf.data(),"0") ){
			std::cout << "[CLIENT] File does not exist on the server.\n";
		}else{
			create_file(buf.data(), message);
		}
		
	    socket.close();		
	}catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
}


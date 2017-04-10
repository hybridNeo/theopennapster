#include <iostream>
#include "com.h"
#include <boost/asio.hpp>
#include <boost/array.hpp>
using boost::asio::ip::tcp;

int send_msg(std::string message){
	std::cout << "[CLIENT] Sending message to the server -- " << message << std::endl;
	boost::asio::io_service io_service;
	boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string("127.0.0.1"), SERVER_PORT);
    
	try{
		boost::asio::ip::tcp::socket socket(io_service);
		socket.connect(endpoint);

		boost::array<char, 128> buf;
  	    	std::copy(message.begin(),message.end(),buf.begin());
	    	boost::system::error_code error;
	    	socket.write_some(boost::asio::buffer(buf, message.size() ), error);	
		socket.read_some(boost::asio::buffer(buf), error);
		std::cout << "[CLIENT] Downloading file: " << buf.data() << std::endl;
	    socket.close();		
	}catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}


}


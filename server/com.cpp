#include <iostream>
#include "com.h"
#include "query.h"
#include <boost/asio.hpp>
#include <boost/array.hpp>
using boost::asio::ip::tcp;
void listen(){

	try{
		std::cout << "[SERVER] Listening for input " << std::endl;
		boost::asio::io_service io_service;
		tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(),SERVER_PORT));
		
		while(1){
			tcp::socket socket(io_service);	
			std::string message = "this is it";	
			boost::array<char, 128> buf;
			acceptor.accept(socket);			
			boost::system::error_code ignored_error,error;
			socket.read_some(boost::asio::buffer(buf), error);
			std::cout << "[SERVER] File requested is: " << buf.data() << std::endl;
			std::string file_path = fetch_file_path(buf.data());	
			std::string file_content = fetch_file_content(file_path);
			std::cout << "File content is " << file_content << std::endl;
			boost::asio::write(socket, boost::asio::buffer(file_content), ignored_error);
			socket.close();
		}
	}catch( std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	
}

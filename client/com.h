#include <iostream>
#include <sys/socket.h>
#include <string>

#define SERVER_PORT 6234
#define CLIENT_PORT 6235
int send_msg(std::string msg);
int send_to_endpoint(std::string& serv_ip , int serv_port , std::string& msg);

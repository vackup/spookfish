/*
   MIT License

   Copyright (c) 2018 santhoshachar08@gmail.com

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in all
   copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.
*/


#include <iostream>
#include <fstream>
#include <string>

#include "TcpClient.hpp"

int main(int argc, char** argv)
{
  if (argc != 4) {
    std::cout << "Usage: ./client <server_ip> <port> <json_file> \n";
    return -1;
  }
  std::string serverIp(argv[1]);
  std::string port(argv[2]);
  std::string jsonFile(argv[3]);
  std::string line("");
  std::string msg("");

  std::ifstream infile(jsonFile);
  while (std::getline(infile, line)) {
    //std::cout << "New line" << line.c_str() << "\n";
    msg += line + "\n";
  }
  std::cout << msg.c_str() << "\n";
  TcpClient client(serverIp, std::stoi(port));
  client.Connect(msg);
  return 0;
}

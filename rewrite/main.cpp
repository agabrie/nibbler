#include <iostream>
#include "math_library.hpp"

std::string request_input(std::string request){
  std::cout << request + ": ";
  std::string input;
  std::cin >> input;
  return input;
}

int main(){
  std::cout << "Hello World\n";
  std::string str1 = request_input("Enter a value");
  std::string str2 = request_input("Enter another value");
  int val1 = std::stoi(str1);
  int val2 = std::stoi(str2);
  int result = add(val1, val2);
  std::cout << "result: " + std::to_string(result) + "\n";
  return 0; 
}
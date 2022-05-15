/**
 * @file move.cc
 * @author Ziheng Zhuang (NeoClear@outlook.com)
 * @brief  This file is to demonstrate the basic usage of move feature in C++
 * @version 0.1
 * @date 2022-05-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>

class Movable {
private:
  std::string name;

public:
  Movable(std::string name_) : name(name_) {
    std::cout << "Calling " << name << ": Movable constructor" << std::endl;
  }

  Movable(Movable&& other) : name(std::move(other.name)) {
    std::cout << "Calling " << name << ": Movable movable constructor" << std::endl;
  }

  Movable& operator=(Movable&& other) {
    name = std::move(other.name);

    std::cout << "Calling " << name << ": Movable movable operator" << std::endl;

    return *this;
  }

  void print() {
    std::cout << name << std::endl;
  }
};

Movable movingFunction(Movable movable) {
  std::cout << "In the body of Movable movingFunction(Movable)" << std::endl;
  return movable;
}

int main() {
  Movable m1("m1");
  Movable m2(std::move(m1));

  Movable m3("m3");
  Movable m4 = std::move(m3);

  Movable m5("m5");

  // Here, move constructor would be called once on argument pass
  // And once on return
  movingFunction(std::move(m5));

  Movable m6("m6");
  Movable m7("m7");

  m7 = std::move(m6);

  return 0;
}

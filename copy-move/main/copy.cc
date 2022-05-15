/**
 * @file copy.cc
 * @author Ziheng Zhuang (NeoClear@outlook.com)
 * @brief This file is to demonstrate the basic usage of copy feature in C++
 * @version 0.1
 * @date 2022-05-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <vector>
#include <iostream>

// This class is used as a nested object whithin Copyable
class CopyableInteger {
private:
  int value;
public:
  // CopyableInteger() {
  //   std::cout << "Calling CopyableInteger default constructor" << std::endl;
  //   value = 0;
  // }

  CopyableInteger(int value) {
    std::cout << "Calling CopyableInteger constructor" << std::endl;
    this->value = value;
  }

  // Copy constructor of CopyableInteger
  CopyableInteger(const CopyableInteger &src) {
    std::cout << "Calling CopyableInteger copy constructor" << std::endl;
    this->value = src.value;
  }

  CopyableInteger& operator=(const CopyableInteger &src) {
    std::cout << "Calling CopyableInteger copy operator" << std::endl;
    value = src.value;
    
    return *this;
  }
};

class Copyable {
private:
  // The date field within Copyable object is merely used for sanity checks
  int integer = 0;

  // Use a non-trivial object within Copyable object to test copy behavior whithin copy behavior
  CopyableInteger copyableInteger;

  // Use a pointer to demonstrate that copy is not simply copying value
  // Sometimes semantics of copy need to be adjusted to reflect the need
  char string[256];

public:
  Copyable(int integer, int copyableValue, char *string) : copyableInteger(copyableValue) {
    std::cout << "Calling Copyable constructor" << std::endl;

    this->integer = integer;
    strcpy(this->string, string);
  }

  // Copy constructor, construct an object by copying another object
  Copyable(const Copyable &src) : copyableInteger(src.copyableInteger) {
    std::cout << "Calling Copyable copy contructor" << std::endl;

    // For integer value, simply use assign
    integer = src.integer;
    strcpy(string, src.string);
  }
};

int main() {
  char literal[] = "string";

  // Calling constructor of Copyable
  // Within Copyable constructor, constructor of CopyableInteger is called
  Copyable copyable(34, 63, literal);

  // Calling copy constructor of Copyable
  // Within copy constructor of copyable, constructor of CopyableInteger
  Copyable copyOfCopyable = copyable;

  return 0;
}

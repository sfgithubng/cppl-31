#include <iostream>
#include <vector>

template<typename T>
T universalPow2(const T&);

template<>
int universalPow2<int>(const int& inputInt) {
  return inputInt * inputInt;
}

template<>
std::vector<int> universalPow2<std::vector<int>>(const std::vector<int>& inputIntVector) {
  std::vector<int> outputIntVector {};
  for (auto inputIntValue : inputIntVector) {
    outputIntVector.push_back(inputIntValue * inputIntValue);
  }

  return outputIntVector;
}

void printIntVectorCommaSeparated(const std::vector<int>& intVectorToPrint) {
  std::string stringToPrint;
  for (auto intToPrint : intVectorToPrint) {
    stringToPrint += std::to_string(intToPrint) + ", ";
  }
  stringToPrint.erase(stringToPrint.size() - 2);
  std::cout << stringToPrint << std::endl;
}

int main() {
  int input1{4};
  auto output1 = universalPow2(input1);
  std::cout << "[IN]: " << input1 << std::endl;
  std::cout << "[OUT]: " << output1 << std::endl;

  std::vector<int> input2{-1, 4, 8};
  auto output2 = universalPow2(input2);
  std::cout << "[IN]: ";
  printIntVectorCommaSeparated(input2);
  std::cout << "[OUT]: ";
  printIntVectorCommaSeparated(output2);

  return EXIT_SUCCESS;
}
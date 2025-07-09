#include <iostream>
#include <vector>

template<typename T>
void universalPrint(T);

template<>
void universalPrint<int>(int intToPrint) {
  std::cout << "[IN]: " << intToPrint << std::endl;
  std::cout << "[OUT]: " << intToPrint * intToPrint << std::endl;
}

template<>
void universalPrint<std::vector<int>>(std::vector<int> intVectorToPrint) {
  std::cout << "[IN]: ";
  std::string inValuesToPrint;
  for (auto intToPrint : intVectorToPrint) {
    inValuesToPrint += std::to_string(intToPrint) + ", ";
  }
  inValuesToPrint.erase(inValuesToPrint.size() - 2);
  std::cout << inValuesToPrint << std::endl;

  std::cout << "[OUT]: ";
  std::string outValuesToPrint;
  for (auto intToPrint : intVectorToPrint) {
    outValuesToPrint += std::to_string(intToPrint * intToPrint) + ", ";
  }
  outValuesToPrint.erase(outValuesToPrint.size() - 2);
  std::cout << outValuesToPrint << std::endl;
}

int main() {
  int input1{4};
  universalPrint(input1);

  std::vector<int> input2{-1, 4, 8};
  universalPrint(input2);

  return EXIT_SUCCESS;
}
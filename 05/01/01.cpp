#include <iostream>
#include <vector>

template<typename T>
T universalPow2(T);

template<>
int universalPow2<int>(int intToPrint) {
  return intToPrint * intToPrint;
}

template<>
std::vector<int> universalPow2<std::vector<int>>(std::vector<int> intVectorToPrint) {
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
  auto output1 = universalPow2(input1);
  std::cout << "[IN]: " << input1 << std::endl;
  std::cout << "[OUT]: " << output1 << std::endl;

  std::vector<int> input2{-1, 4, 8};
  auto output2 = universalPow2(input2);
  std::cout << "[IN]: ";
  std::string inValuesToPrint;
  for (auto intToPrint : input2) {
    inValuesToPrint += std::to_string(intToPrint) + ", ";
  }
  inValuesToPrint.erase(inValuesToPrint.size() - 2);
  std::cout << inValuesToPrint << std::endl;

  std::cout << "[OUT]: ";
  std::string outValuesToPrint;
  for (auto intToPrint : output2) {
    outValuesToPrint += std::to_string(intToPrint * intToPrint) + ", ";
  }
  outValuesToPrint.erase(outValuesToPrint.size() - 2);
  std::cout << outValuesToPrint << std::endl;

  return EXIT_SUCCESS;
}
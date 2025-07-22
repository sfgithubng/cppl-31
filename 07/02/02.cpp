#include <iostream>
#include <set>

std::set<int32_t, std::greater<int32_t>> getInputSet() {
  std::string userInputString;
  std::cout << "[IN]:" << std::endl;
  std::getline(std::cin, userInputString);
  int32_t numOfInputInts{std::stoi(userInputString)};
  std::set<int32_t, std::greater<int32_t>> userInputInts;
  for (int32_t inputElementNumber = 0; inputElementNumber < numOfInputInts; ++inputElementNumber) {
    std::getline(std::cin, userInputString);
    userInputInts.insert(std::stoi(userInputString));
  }
  return userInputInts;
}

void printInputSet(std::set<int32_t, std::greater<int32_t>> userInputInts) {
  std::cout << "[OUT]:" << std::endl;
  for (const auto& userInputInt : userInputInts) {
    std::cout << userInputInt << std::endl;
  }
}

int main() {
    std::set<int32_t, std::greater<int32_t>> userInputInts = getInputSet();
    printInputSet(userInputInts);
    return EXIT_SUCCESS;
}
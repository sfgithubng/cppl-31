#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

std::vector<int32_t> filterOutVectorDuplicates(const std::vector<int32_t>& inputVector) {
  auto outputVector = inputVector;
  std::sort(outputVector.begin(), outputVector.end());
  auto lastElement = std::unique(outputVector.begin(), outputVector.end());
  outputVector.erase(lastElement, outputVector.end());

  return outputVector;
}

void printInt32VectorSpaceSeparated(const std::vector<int32_t>& vectorToPrint) {
  std::string stringToPrint = "";
  for (const auto& intElement : vectorToPrint) {
    stringToPrint += std::to_string(intElement) + " ";
  }
  stringToPrint.erase(stringToPrint.size() - 1);
  std::cout << stringToPrint << std::endl;
}

int main() {
  std::vector<int32_t> inputVector{1, 1, 2, 5, 6, 1, 2, 4};
  std::cout << "[IN]: ";
  printInt32VectorSpaceSeparated(inputVector);

  auto sortedVector = filterOutVectorDuplicates(inputVector);
  std::cout << "[OUT]: ";
  printInt32VectorSpaceSeparated(sortedVector);

  return EXIT_SUCCESS;
}

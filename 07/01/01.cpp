#include <iostream>
#include <map>

int main() {
  std::string inputStr{"Hello world!!"};
  std::cout << "[IN]: " << inputStr << std::endl;

  std::map<char, int32_t, std::greater<int32_t>> charFrequencyMap {};
  for (const auto& inputChar : inputStr) {
    charFrequencyMap[inputChar] += 1;
  }

  std::multimap<int32_t, char, std::greater<int32_t>> inversedCharFrequencyMap {};
  for (const auto& [strChar, frequency] : charFrequencyMap) {
    inversedCharFrequencyMap.insert({frequency, strChar});
  }

  std::cout << "[OUT]: " << std::endl;
  for (const auto& [frequency, strChar] : inversedCharFrequencyMap) {
    std::cout << strChar << ": " << frequency << std::endl;
  }

  return EXIT_SUCCESS;
}
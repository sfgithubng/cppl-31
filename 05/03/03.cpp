#include <algorithm>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>

class get_sum {
private:
  int32_t sumValue;
public:
  explicit get_sum() : sumValue{0} {}

  void operator()(int32_t mod3Candidate) {
    if ((mod3Candidate % 3) == 0) {
      sumValue += mod3Candidate;
    }
  }

  operator int32_t() {
    return sumValue;
  }
};

class get_count {
private:
  int32_t countValue;
public:
  explicit get_count() : countValue{0} {}

  void operator()(int32_t mod3Candidate) {
    if ((mod3Candidate % 3) == 0) {
      ++countValue;
    }
  }

  operator int32_t() {
    return countValue;
  }
};

int main() {
  std::vector<int32_t> intsToCalc{4, 1, 3, 6, 25, 54};
  std::cout << "[IN]: ";
  for(auto valueToPrint : intsToCalc) {
    std::cout << valueToPrint << " ";
  }
  std::cout << std::endl;

  int32_t testSum = std::for_each(intsToCalc.begin(), intsToCalc.end(), get_sum());
  std::cout << "[OUT]: get_sum() = " << testSum << std::endl;

  int32_t testCount = std::for_each(intsToCalc.begin(), intsToCalc.end(), get_count());
  std::cout << "[OUT]: get_count() = " << testCount << std::endl;

  return EXIT_SUCCESS;
}
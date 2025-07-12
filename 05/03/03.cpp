#include <algorithm>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>

class Counter {
private:
  int32_t sumValue;
  int32_t countValue;
public:
  explicit Counter() : countValue{0}, sumValue{0} {}

  void operator()(int32_t mod3Candidate) {
    if ((mod3Candidate % 3) == 0) {
      sumValue += mod3Candidate;
      countValue++;
    }
  }

  int32_t get_sum() const {
    return sumValue;
  }

  int32_t get_count() const {
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

  Counter counter = std::for_each(intsToCalc.begin(), intsToCalc.end(), Counter());
  std::cout << "[OUT]: get_sum() = " << counter.get_sum() << std::endl;
  std::cout << "[OUT]: get_count() = " << counter.get_count() << std::endl;

  return EXIT_SUCCESS;
}
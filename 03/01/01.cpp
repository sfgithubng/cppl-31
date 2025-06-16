#include <iostream>
#include <cstdint>

class smart_array {
private:
  int32_t currentElements;
  int32_t maxElements;
  static const int32_t defaultMaxElements{50};
  int32_t* smartArray = nullptr;

public:
  smart_array() : smart_array(defaultMaxElements) {
  }

  explicit smart_array(int32_t constrMaxElements) : maxElements{constrMaxElements} {
    smartArray = new int[maxElements];
    currentElements = 0;
  }

  void add_element(int32_t elementToAdd) {
    if (currentElements == maxElements) {
      maxElements = maxElements * 2;
      int *newSmartArray = new int[maxElements];
      for (int arrIndex = 0; arrIndex < currentElements; ++arrIndex) {
        newSmartArray[arrIndex] = smartArray[arrIndex];
      }
      delete[] smartArray;
      smartArray = newSmartArray;
    }
    ++currentElements;
    smartArray[currentElements - 1] = elementToAdd;
  }

  int32_t get_element(uint32_t elementNumber) {
    if (elementNumber < currentElements) {
      return smartArray[elementNumber];
    } else {
      throw std::invalid_argument("Invalid element number requested");
    }
  }

  smart_array(const smart_array& otherSmartArray) = delete;
  smart_array & operator=(const smart_array& otherSmartArray) = delete;

  ~smart_array() {
    delete[] smartArray;
  }

};

int main() {
  try {
    smart_array arr(4);
    arr.add_element(1);
    arr.add_element(4);
    arr.add_element(155);
    arr.add_element(14);
    arr.add_element(15);
    arr.add_element(20);
    std::cout << arr.get_element(1) << std::endl;
    std::cout << arr.get_element(5) << std::endl;
    std::cout << arr.get_element(30) << std::endl;
  }
  catch (const std::exception& ex) {
    std::cout << ex.what() << std::endl;
  }
  return EXIT_SUCCESS;
}
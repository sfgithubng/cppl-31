#include <iostream>

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

  int32_t get_element(u_int32_t elementNumber) {
    if (elementNumber < currentElements) {
      return smartArray[elementNumber];
    } else {
      throw std::invalid_argument("Invalid element number requested");
    }
  }

  smart_array(const smart_array& otherSmartArray) :
    currentElements(otherSmartArray.currentElements),
    maxElements(otherSmartArray.maxElements) {

    smartArray = new int[maxElements];
    for (int arrIndex = 0; arrIndex < currentElements; arrIndex++) {
      smartArray[arrIndex] = otherSmartArray.smartArray[arrIndex];
    }
  }

  smart_array& operator=(const smart_array& otherSmartArray) {
    smartArray = new int[maxElements];
    for (int arrIndex = 0; arrIndex < currentElements; arrIndex++) {
      smartArray[arrIndex] = otherSmartArray.smartArray[arrIndex];
    }
    return *this;
  }

  ~smart_array() {
    delete[] smartArray;
  }

};

int main() {
  try {
    smart_array arr1(4);
    arr1.add_element(1);
    arr1.add_element(4);
    arr1.add_element(155);
    arr1.add_element(14);
    arr1.add_element(15);
    arr1.add_element(20);
    std::cout << "Printing from array 1" << std::endl;
    std::cout << arr1.get_element(1) << std::endl;
    std::cout << arr1.get_element(5) << std::endl;
    std::cout << arr1.get_element(30) << std::endl;

    smart_array arr2(2);
    arr2.add_element(80);
    arr2.add_element(36);
    arr2.add_element(62);
    arr2.add_element(486);
    std::cout <<"Printing from array 2" << std::endl;
    std::cout << arr1.get_element(2) << std::endl;
    std::cout << arr1.get_element(0) << std::endl;

    arr1 = arr2;
    std::cout << "Printing all values of array 1 after array 2 was assigned to it" << std::endl;
    std::cout << arr1.get_element(0) << std::endl;
    std::cout << arr1.get_element(1) << std::endl;
    std::cout << arr1.get_element(2) << std::endl;
    std::cout << arr1.get_element(3) << std::endl;

  }
  catch (const std::exception& ex) {
    std::cout << ex.what() << std::endl;
  }
  return EXIT_SUCCESS;
}
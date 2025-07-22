#include <iostream>
#include <cstdint>

template<class T>
class myVector {
private:
  int32_t currentElements;
  int32_t maxElements;
  static const int32_t defaultMaxElements{50};
  int32_t* vectorPtr = nullptr;

public:
  myVector() : myVector(defaultMaxElements) {
  }

  explicit myVector(int32_t constrMaxElements) : maxElements{constrMaxElements} {
    vectorPtr = new int32_t[maxElements];
    currentElements = 0;
  }

  int32_t at(int32_t elementNumber) {
    if (elementNumber < currentElements) {
      return vectorPtr[elementNumber];
    } else {
      throw std::invalid_argument("Invalid element number requested");
    }
  }

  void push_back(T elementToPush) {
    if (currentElements == maxElements) {
      maxElements = maxElements * 2;
      int *newVectorPtr = new int32_t[maxElements];
      for (int arrIndex = 0; arrIndex < currentElements; ++arrIndex) {
        vectorPtr[arrIndex] = vectorPtr[arrIndex];
      }
      delete[] vectorPtr;
      vectorPtr = newVectorPtr;
    }
    ++currentElements;
    vectorPtr[currentElements - 1] = elementToPush;
  }

  int32_t size() {
    return currentElements;
  }

  int32_t capacity() {
    return maxElements;
  }

  myVector(const myVector& otherMyVector) = delete;
  myVector & operator=(const myVector& otherMyVector) = delete;

  ~myVector() {
    delete[] vectorPtr;
  }
};

int main() {
  try {
    myVector<int32_t> testVector(2);
    std::cout << "testVector element count: " << testVector.size() << std::endl;
    std::cout << "testVector capacity: " << testVector.capacity() << std::endl;
    std::cout << "pushing back 1 to testVector (position 0) " << std::endl;
    testVector.push_back(1);
    std::cout << "pushing back 3 to testVector (position 1) " << std::endl;
    testVector.push_back(3);
    std::cout << "pushing back 5 to testVector (position 2) " << std::endl;
    testVector.push_back(5);
    std::cout << "testVector capacity after 3 elements have been added: " << testVector.capacity() << std::endl;
    std::cout << "testVector.at(0) is: " << testVector.at(0) << std::endl;
    std::cout << "testVector.at(1) is: " << testVector.at(1) << std::endl;
    std::cout << "testVector.at(2) is: " << testVector.at(2) << std::endl;
    std::cout << "testVector.at(3) is an exception: "; std::cout << testVector.at(3);
  }
  catch (const std::exception& ex) {
    std::cout << ex.what() << std::endl;
  }

  return EXIT_SUCCESS;
}

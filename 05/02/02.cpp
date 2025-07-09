#include <iostream>
#include <cstdint>

template<class T>
class universalArray {
private:
  uint32_t numRows;
  uint32_t numCols;
  uint32_t defaultRowsAndCols = 1;
  T** array;

public:
  universalArray() : universalArray(defaultRowsAndCols, defaultRowsAndCols) {

  }

  explicit universalArray(uint32_t constrNumRows, uint32_t constrNumCols) :
    numCols{constrNumCols},
    numRows{constrNumRows} {
    array = new T*[numRows];
    uint32_t arrayFiller{0};
    for (uint32_t row = 0; row < numRows; row++) {
      array[row] = new T[numCols];
      for (uint32_t col =0; col < numCols; col++) {
        array[row][col] = arrayFiller++;
      }
    }
  }

  universalArray(const universalArray& otherUniversalArray) = delete;
  universalArray & operator=(const universalArray& otherUniversalArray) = delete;

  ~universalArray() {
    for (int32_t row = 0; row < numRows; ++row) {
      delete[] array[row];
    }
    delete[] array;
  }

  class UniversalArrayRow {
  private:
    uint32_t numCols;
    T* arrayRow;
  public:
    UniversalArrayRow(T* constrArrayRow, uint32_t constrNumCols) : arrayRow(constrArrayRow), numCols(constrNumCols) {}

    auto operator[](uint32_t col) const {
      if (col >= numCols) {
        throw std::out_of_range("Invalid row requested");
      }
      return arrayRow[col];
    }

    auto& operator[](uint32_t col) {
      if (col >= numCols) {
        throw std::out_of_range("Invalid row requested");
      }
      return arrayRow[col];
    }

    UniversalArrayRow(const universalArray& otherUniversalArrayRow) = delete;
    UniversalArrayRow & operator=(const universalArray& otherUniversalArrayRow) = delete;

    ~UniversalArrayRow() = default;
  };

  auto operator[](uint32_t row) const {
    if (row >= numRows) {
      throw std::out_of_range("Invalid row requested");
    }
    return UniversalArrayRow(array[row], numCols);
  }

  auto operator[](uint32_t row) {
    if (row >= numRows) {
      throw std::out_of_range("Invalid row requested");
    }
    return UniversalArrayRow(array[row], numCols);
  }
};

int main() {
  auto testArray = universalArray<uint32_t> (3,3);
  auto testArray2 = universalArray<double> (3,3);

  std::cout << "universalArray<uint32_t> [2][1] default value: ";
  std::cout << testArray[2][1] << std::endl;
  std::cout << "universalArray<uint32_t> [2][1] value changed to 8: ";
  testArray[2][1] = 8;
  std::cout << testArray[2][1] << std::endl << std::endl;

  std::cout << "universalArray<double> [0][1] default value: ";
  std::cout << testArray2[0][1] << std::endl;
  std::cout << "universalArray<double> [0][1] value changed to 5: ";
  testArray2[0][1] = 5;
  std::cout << testArray2[0][1] << std::endl << std::endl;
  return EXIT_SUCCESS;
}
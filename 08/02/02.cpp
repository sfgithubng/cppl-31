#include <iostream>
#include <cstdlib>
#include <list>
#include <set>
#include <vector>

template<typename T>
void print_container(const T& containerToPrint) {
  std::string stringToPrint = "";
  for (const auto& containerElement : containerToPrint) {
    stringToPrint += containerElement + " ";
  }
  stringToPrint.erase(stringToPrint.size() - 1);
  std::cout << stringToPrint << std::endl;
}

int main() {
  std::set<std::string> stringSet{"one", "two", "three", "four"};
  print_container(stringSet);

  std::vector<std::string> stringVector{"one", "two", "three", "four"};
  print_container(stringVector);

  std::list<std::string> stringList{"one", "two", "three", "four"};
  print_container(stringList);

  return EXIT_SUCCESS;
}
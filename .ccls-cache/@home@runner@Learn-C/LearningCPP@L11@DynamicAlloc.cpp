#include <algorithm>
#include <array>
#include <iostream>
#include <string>

int main() {

  int *pTmpInt{new int{1}};
  if (!pTmpInt) {
    std::cerr << "error new int cannot be allocated";
    return 1;
  }

  int *array{new int[5]{1, 2, 3, 4, 5}};

  std::cout << *pTmpInt << "\n";

  delete pTmpInt;
  pTmpInt = nullptr;
  delete[] array;
  array = nullptr;

  int numberOfNames{0};
  std::cout << "how many names do you want to enter ?";
  // std::cin>>numberOfNames;
  numberOfNames = 5;

  std::string *namesArray{new std::string[numberOfNames]};

  for (int i{0}; i < numberOfNames; ++i) {
    std::cout << "enter name " << i << "\n";
  }

  namesArray[0] = "jeff";
  namesArray[1] = "amely";
  namesArray[2] = "dona";
  namesArray[3] = "francis";
  namesArray[4] = "waldo";

  std::sort(namesArray, namesArray + numberOfNames);

  for (int i{0}; i < numberOfNames; ++i) {
    std::cout << "name " << namesArray[i] << "\n";
  }

  delete[] namesArray;

  std::array<double, 8> arrayDouble {1.2,5.8,7.5};

      return 0;
}
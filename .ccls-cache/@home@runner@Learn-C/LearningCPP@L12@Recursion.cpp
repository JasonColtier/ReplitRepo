#include <iostream>

// A factorial of an integer N (written N!) is defined as the product
// (multiplication) of all the numbers between 1 and N (0! = 1)

int factorial(int n) {
  if (n <= 0)
    return 1;

  return factorial(n - 1) * n;
}

// Write a recursive function that takes an integer as input and returns the sum
// of each individual digit in the integer (e.g. 357 = 3 + 5 + 7 = 15). Print
// the answer for input 93427 (which is 25). Assume the input values are
// positive.

int numberSum(int number) {

  // std::cout << "current number : " << number << "\n";

  if (number < 10) {
    std::cout << "identified a digit : " << number << "\n";
    return number;
  }

  int result = numberSum(number / 10) + number % 10;
  std::cout << "identified a digit : " << number % 10 << "\n";
  return result;
}

void PrintNumberToBit(int number) {

  if (number <= 0) {
    std::cout << "\n";
    return;
  }

  PrintNumberToBit(number / 2);

  std::cout<< number % 2;

}

int main() {
  for (int count{0}; count < 7; ++count)
    std::cout << factorial(count) << '\n';

  std::cout << "number sum : \n" << numberSum(93427) << "\n";

  // 148 = 1001 0100
  PrintNumberToBit(148);
  PrintNumberToBit(2);
}
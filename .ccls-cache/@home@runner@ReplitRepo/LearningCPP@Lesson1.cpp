#include <iostream>
using namespace std;

int main() {

  // initialisation des variables

  int a = 2, b = 7; // multiple variables declaration in single line
  // = means copy initialisation

  int c(3); // direct initialisation, not used much

  int listInit{4};        // direct list initialisation
  int ListInitCopy = {4}; // copy list init

  // int notCompiling {4.5}; //dissallowed in list initialisation
  int compiling = 4.5;

  int valueInit{}; // value init != from no init. Here it holds 0
  // Use value initialization if the value is temporary and will be replaced.

  cout << "hello ! " << a << b << c << listInit << valueInit << endl;

  cout << "write an int  pls : ";
  int userValue{};
  //cin >> userValue;

  cout << "user value is : " << userValue << endl;
  return 0;
}

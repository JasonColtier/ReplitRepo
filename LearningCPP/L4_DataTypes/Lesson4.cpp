#include "iostream"
#include "string_view"

using namespace std;

//https://www.learncpp.com/cpp-tutorial/chapter-4-summary-and-quiz/

void PrintString(string_view str){
  cout<<str<<endl;
}

int main(){

  cout<<sizeof(bool)<<endl;
  cout<<sizeof(char)<<endl;
  cout<<sizeof(short)<<endl;
  cout<<sizeof(int)<<endl;
  cout<<sizeof(wchar_t)<<endl;
  cout<<sizeof(float)<<endl;
  cout<<sizeof(double)<<endl;
  cout<<sizeof(long)<<endl;


  unsigned short x = (2e16)-2;
  cout<<"x is : "<<x<<endl;

  	std::cout << "least 8:  " << sizeof(std::int_least8_t) * 8 << " bits\n";
	std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
	std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
	std::cout << '\n';
	std::cout << "fast 8:  " << sizeof(std::int_fast8_t) * 8 << " bits\n";
	std::cout << "fast 16: " << sizeof(std::int_fast16_t) * 8 << " bits\n";
	std::cout << "fast 32: " << sizeof(std::int_fast32_t) * 8 << " bits\n";


  cout<<sizeof(size_t)<<endl;


/* Write a short program where the user is asked to enter a single character. Print the value of the character and its ASCII code, using static_cast.

The program’s output should match the following:

Enter a single character: a
You entered 'a', which has ASCII code 97. */

char userInput {'a'};

  int implicitConv = userInput;

  cout<<static_cast<int>(userInput)<<endl;
  cout<<implicitConv<<endl;

  constexpr int CompileTimeConstant {5+8};

  string_view s = "Hello !!";
  PrintString(s);
  
  return 0;
}
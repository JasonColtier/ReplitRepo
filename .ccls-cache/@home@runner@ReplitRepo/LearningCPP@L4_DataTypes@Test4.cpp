/*
Write the following program: The user is asked to enter 2 floating point numbers (use doubles). The user is then asked to enter one of the following mathematical symbols: +, -, *, or /. The program computes the answer on the two numbers the user entered and prints the results. If the user enters an invalid symbol, the program should print nothing.
*/

#include "iostream"
#include "iomanip"

using namespace std;

int main(){

  cout<<"Enter first floating number \n";
  //cin>>x;
  double userInput1 {6.154135743};
  cout<<"Enter second floating number \n";
  double userInput2 {5454.154544454f};
  cout<<"enter operation sign\n";
  char operation {'-'};

  cout<<"final output : \n";
  switch(operation){
   
    case '-':
      double res = userInput1-userInput2;
      cout<<fixed;
      cout<<setprecision(5);
      cout<<res;
    break;
  }

  

  return 0;
}
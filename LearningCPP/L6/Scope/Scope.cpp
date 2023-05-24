#include "iostream"

using namespace std;

int main(){

  cout<<"enter a small int \n";
  int x = 3;

cout<<"enter a bigger int \n";
  int y = 2;
  
  if(x>y){
    auto swap = x;
    x=y;
    y=swap;
  }

  cout<<"small and big : "<<x<<" "<<y;

} 
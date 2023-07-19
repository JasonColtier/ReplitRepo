#include <iostream>
#include <string>

int main(){

  std::string fav = "banana";

  fav = "lemon";
  
  
  auto print{
    [=](){
      std::cout << fav;
    }  
  };

  
  print();
  
  
  return 0;
}



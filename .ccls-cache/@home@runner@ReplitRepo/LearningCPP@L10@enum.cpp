#include <iostream>
#include <string_view>

enum class Animals {
Camel,
Fish,
Bird
};


std::string_view getAnimalName(Animals animal){

switch(animal){
  case Animals::Fish : return "Fish";
  default : return "error";

  
}


  
}



int main(){
  std::cout<<getAnimalName(Animals::Fish);



  return 0;
}
#include "iostream"


void Print(){
  std::cout<<"global print";
}

namespace math{

void Print(){
  std::cout<<"math print";
}

void Add(){
  std::cout<<"math";
  Print();
  ::Print();
}
}

namespace number{
void Add(){}
}




int main()
{
  math::Add();

  return 0;
}
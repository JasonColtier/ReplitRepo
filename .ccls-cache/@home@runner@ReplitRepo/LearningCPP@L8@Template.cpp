#include <iostream>

template <typename T>
T Add(T left,T right){
  return (left+right);
}


int main(){

  double x {1.25};
  double y {2.7815};
  
  std::cout<<Add(x, y);
  
  return 0;
}
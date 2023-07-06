#include <iostream>


template<typename T>
T* FindValue(T* begin, T* end, T value){
  for(T* i {begin};i != end;++i){
    if(*i == value){
      return i;
    }
  }
  return end;
}






int main(){

  int arr[]{0,8,6,71,54,23,84,21,12};
  
  int* found {FindValue(std::begin(arr), std::end(arr), 22)};

  if(found != std::end(arr)){
    std::cout<< "elemen found ! "<<*found<< "\n";
  }else{
    std::cout<< "elemen NOT found ! \n";
  }

  return 0;
}
#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>
#include <iterator>

template<typename T>

void PrintContainer(const std::vector<T>& v){
  for(auto itBegin {v.begin()};itBegin != v.end();++itBegin){
    std::cout<<"elem : "<<*itBegin<<"\n";
  }
}

int main() {
  
  std::vector<int> vec {2,8,9,66,445545};
  //also works with std::array
  
  std::cout<<"vec size : "<<vec.size()<<"\n";

  PrintContainer<int>(vec);
  
  return 0; 

}
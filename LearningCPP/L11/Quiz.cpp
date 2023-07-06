#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <string_view>
#include <vector>

enum Items { potion, torche, arrow, maxItem };

using Inventory = std::array<int, Items::maxItem>;

int countTotalItems(Inventory &inventory) {
  return std::reduce(inventory.begin(), inventory.end());
}


struct Student{
  std::string_view name {};
  int grade {};
};

bool compareStudent(const Student& a, const Student& b){
  if(a.grade > b.grade)
    return true;
  return false;
}

void PrintStudents(const std::vector<Student>& vecToPrint){
  for(const auto& elem : vecToPrint){
    std::cout<<" student "<<elem.name<<" got grade "<<elem.grade<<"\n";
  }
}

template <typename T>
void swapValues(T& a,T&b){
  //std::swap(a,b);
  T tmp {a};
  a = b;
  b = tmp;
}

void CStylePrinter(char* begin){
  for(char* i{begin};*i!='\0';++i){
    std::cout<<"char : "<<*i<<"\n";
  }
}

int main() {

  Inventory inv { 2, 5, 8 };

  std::cout<<"number of items : "<<countTotalItems(inv)<<"\n";

  Student s {"sam",15};
  Student d {"dim",12};
  Student e {"etien",9};
  Student f {"flavien",20};
  std::vector<Student> vec {s,d,e,f};

  std::sort(vec.begin(),vec.end(),compareStudent);

  PrintStudents(vec);

  int swappingA {12};
  int swappingB {523};

  swapValues(swappingA,swappingB);

  std::cout<<"a : "<<swappingA<<" \n";
  std::cout<<"b : "<<swappingB<<" \n";

  CStylePrinter("hello world!");

  return 0;
}
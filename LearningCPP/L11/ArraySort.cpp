#include <iostream>
#include <iterator>

int main(){

  int sort[] {30,60,20,40,50,10};

  for(int i {0};i<std::size(sort)-1;++i){   
    int smallestIndex;
    smallestIndex = {i};
    for(int j{i};j<std::size(sort);++j)
    {
       if(sort[j]>sort[smallestIndex] ){
        
         smallestIndex = j;
       //std::cout<<"new smallest :"<<smallest.value<<" at index"<<smallest.index<<" loop I "<<i<<" loop j "<<j<<"\n";

       }
    };
    

 
std::swap(sort[i],sort[smallestIndex]);
    std::cout<<"swapped "<<sort[i]<< "and "<<sort[smallestIndex]<< "\n";
  
  
}   

 for(int i {0};i<std::size(sort);++i){
    std::cout<<" | elem : "<<sort[i]; 
  } 



std::cout<<"\n\n\n\n";



  //bubble sort
  int bubble[] {3,9,8,4,1,2,6,5,7};

  int length{static_cast<int>(std::size(bubble))};

  for(int i{0};i<length;++i){
   
   for(int j{0};j<length-1-i;++j){

     if(bubble[j]>bubble[j+1]){
                   std::swap(bubble[j],bubble[j+1]);
     } 

    std::cout<<"j loop number : "<<j<<"\n"; 
   }

    
  }

  
for(int i {0};i<length;++i){
    std::cout<<" | elem : "<<bubble[i]; 
  }   

  return 0;
}
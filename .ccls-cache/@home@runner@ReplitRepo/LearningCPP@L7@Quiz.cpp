#include "Quiz.h"
#include "../Constants/Constants.h"
#include <iostream>

float const CalculateFallDistance(const float time) {

  float distance = time*Constants::gravity *time ;
  
  
  std::cout<<"at time "<<time<<", ball has fallen "<<distance<<"m\n";

  return distance;
}

int main(){

std::cout<<"begin program";

  const float initialHeight {150};

  float currentHeight = initialHeight;
  int time {0};

while(currentHeight > 0){
  currentHeight -= CalculateFallDistance(time);

  time++;
}
  


  
  return 0 ;
}
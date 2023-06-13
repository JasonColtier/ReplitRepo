#include <iostream>

struct Animal{
int age {0};
std::string name {"unamed dog"};
int loveLevel {0};

void printAnimal(){
  std::cout<<"age : "<<age<<", name : "<<name<<", loveLevel : "<<loveLevel<<"\n";
}
};

struct DailyMoney{
  int numberOfAdsShown {0};
  float percentageOfAdsClicked {0};
  float earnedMoney{0};
};

void PrintDailyMoney(DailyMoney& money){
  std::cout<<"Ads : "<<money.numberOfAdsShown<<" percentage clicked : "<<money.percentageOfAdsClicked<< " money : "<<money.earnedMoney<< "\n";

  std::cout<<" total : "<< money.numberOfAdsShown * money.percentageOfAdsClicked * money.earnedMoney << " \n";
}

struct Fraction{
  int numerator {1};
  int denumerator {1};

  Fraction operator*(const Fraction other){
    return Fraction(
      {this->numerator * other.numerator},
      {this->denumerator * other.denumerator}
      );
  }
};

void PrintFraction(const Fraction& printedFrac){
  std::cout<<printedFrac.numerator<< " / "<<printedFrac.denumerator << " \n";
}


int main(){

  Animal dog {2,"dogo",10};

  dog.printAnimal();
  dog = {3,dog.name,9};
  dog.printAnimal();
  dog = {.age=4,.name = "newDogo",.loveLevel = 8};
  dog.printAnimal();

  DailyMoney money {10,2.35,58.24};
  //std::cout << "what is the percentage of ads clicked ?";
  //std::cin >> money.percentageOfAdsClicked;
  PrintDailyMoney(money);

  Fraction f1 {1,2};
  Fraction f2 {3,4};

  PrintFraction(f1*f2);
  
  return 0;
}
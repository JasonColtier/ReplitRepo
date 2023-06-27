#include <iostream>

enum MonsterType{
Orc,
Spider, 
Gobelin
};

struct Monster{
MonsterType type;
int health {1};
std::string name {"unnamed monster"};
};

std::ostream& operator<<(std::ostream& stream,const MonsterType monsterType){
  switch (monsterType){
    case Orc : 
      return stream<<"Orc";
    case Spider : 
      return stream<<"Spider";
    case Gobelin : 
      return stream<<"Gobelin";
    default :
    return stream<<"name not implemented";
  }  
}

void PrintMonster(Monster& monster){
std::cout<<monster.type<<" named "<<monster.name<< " has "<<monster. health<<"HP \n";  
}


template<typename T>
struct Triad{
T arg1;
T arg2;
T arg3;
};


template<typename T>
Triad(T,T,T) -> Triad<T>;

template<typename T>
void PrintTriad(const Triad<T>& triad){
  std::cout<<"["<<triad.arg1<<triad.arg2<<triad.arg3<<"]\n";
}


int main () {

Monster spider{Spider,10,"spidy"};

PrintMonster(spider);

Triad t1{1,2,3};
  PrintTriad(t1);

  Triad t2{1.2,3.4,5.6};
  PrintTriad(t2);
  
  

return 0 ;
} 

#include <iostream>
#include "../L14/Point2D.h"

using std::ostream;

class Shape{

public :
virtual ~Shape(){};

virtual ostream& print(ostream& stream ) const = 0;

friend ostream& operator<<(ostream& stream,const Shape& shape){

  return shape.print(stream);
}

};

class Triangle : public Shape
{
Point2D m_p1 {};
Point2D m_p2{};
Point2D m_p3{};

public:
Triangle(Point2D p1,Point2D p2, Point2D p3):m_p1(p1),m_p2(p2),m_p3(p3) {
  
}

ostream& print(ostream& stream) const override{
return stream << "{"<< m_p1 << m_p2 << m_p3<<"}" ;  
}



};

class Circle : public Shape{

public:
Point2D m_center {};
int m_radius {1};


Circle(Point2D p, int r):m_center(p),m_radius(r) {
  
}

ostream& print(ostream& stream) const override{
return stream<< m_center<<" r="<<m_radius;
  
}


};


int getLargestRadius(const std::vector<Shape*>& v){

  int largest=0;
  
  for(auto* s : v){
    Circle* c = dynamic_cast<Circle*>(s);
    if(c != nullptr){
      //if(c->m_radius > largest)
        //largest = c->m_radius;
      largest=std::max(largest,c->m_radius);
    }
  }

  return largest;
 
  
}


int main(){

  
//Circle c{ Point2D{ 1, 2 }, 7 };
    //std::cout << c << '\n';

   // Triangle t{Point2D{ 1, 2 }, Point2D{ 3, 4 }, Point2D{ 5, 6 }};
    //std::cout << t << '\n';


std::vector<Shape*> v{
	  new Circle{Point2D{ 1, 2 }, 7},
	  new Triangle{Point2D{ 1, 2 }, Point2D{ 3, 4 }, Point2D{ 5, 6 }},
	  new Circle{Point2D{ 7, 8 }, 3}
	};


  

      for(const auto* s : v){
        std::cout<<*s<<"\n";
      }
	// print each shape in vector v on its own line here

	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

  for(const auto* s : v){
        delete s;
  }
	// delete each element in the vector here


  return 0 ;
}
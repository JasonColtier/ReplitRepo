#include <iostream>

template <typename T> class Pair1 {
  T m_first;
  T m_second;

public:
  Pair1(T first, T second) : m_first(first), m_second(second) {}

  T first() const { return m_first; };
  T second() const { return m_second; };
};

template <typename T, typename U> class Pair {
  T m_first;
  U m_second;

public:
  Pair(T first, U second) : m_first(first), m_second(second) {}

  T first() const { return m_first; };
  U second() const { return m_second; };
};

template <typename T> class StringValuePair : public Pair<std::string,T>{

public:
  StringValuePair(std::string first, T second) : Pair<std::string,T>(first,second) {}

};

int main() {

  Pair1<int> p1{5, 8};
  std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

  const Pair1<double> p2{2.3, 4.5};
  std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

  Pair<int, double> p3{5, 6.7};
  std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

  const Pair<double, int> p4{2.3, 4};
  std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

  StringValuePair<int> svp{"Hello", 5};
  std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

  return 0;
}
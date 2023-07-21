#include "iostream"

class Ball {

public:

//    Ball() = default;
//
//    Ball(const std::string& color){
//        m_color = color;
//    }
//    Ball(const double radius){
//        m_radius = radius;
//    }
//    Ball(const std::string& color,const double radius){
//        m_color = color;
//        m_radius = radius;
//    }

    Ball(const std::string& color = "black", const double radius = 10.0) {
        m_color = color;
        m_radius = radius;
    }

    Ball(const double radius) {
        m_radius = radius;
    }

    void print() {
        std::cout << "color : " << m_color << ", radius : " << m_radius << "\n";
    }

private:
    std::string m_color{"black"};
    double m_radius{10};
};


class RGBA {

public:
    RGBA(std::uint8_t red = 0, std::uint8_t green = 0, std::uint8_t blue = 0, std::uint8_t alpha = 255) :
            m_red{red}, m_green{green}, m_blue{blue}, m_alpha{alpha} {
    }

    void print() {
        std::cout << "r=" << static_cast<int>(m_red) << " g=" << static_cast<int>(m_green) << " b="
                  << static_cast<int>(m_blue) << " a=" << static_cast<int>(m_alpha) << "\n";
    }

private:
    std::uint8_t m_red{};
    std::uint8_t m_green{};
    std::uint8_t m_blue{};
    std::uint8_t m_alpha{};
};


class AllocatedMem {


public:
    AllocatedMem() {
        m_array = new int[1000000];
        std::cout<<"New array allocated \n";
    }

    ~AllocatedMem() {
        delete[] m_array;
        std::cout<<"New array deleted \n";
    }
private:
    int* m_array = nullptr;


};


int main() {
    Ball def{};
    def.print();

    Ball blue{"blue"};
    blue.print();

    Ball twenty{20.0};
    twenty.print();

    Ball blueTwenty{"blue", 20.0};
    blueTwenty.print();

    RGBA teal{0, 127, 127};
    teal.print();

    AllocatedMem allocatedMem;

    return 0;
}
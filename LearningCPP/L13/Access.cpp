#include "iostream"

class Point3d {

    int m_cooX{};
    int m_cooY{};
    int m_cooZ{};

public :

    void setValues(const int x, const int y, const int z) {
        m_cooX = x;
        m_cooY = y;
        m_cooZ = z;
    }

    void print() const {
        std::cout << "x=" << m_cooX << " y=" << m_cooY << " z=" << m_cooZ;
    }

    bool isEqual(const Point3d& otherPoint) const {
        return otherPoint.m_cooX == this->m_cooX
               && otherPoint.m_cooY == this->m_cooY
               && otherPoint.m_cooZ == this->m_cooZ;
    }
};


int main() {
    Point3d point1;
    point1.setValues(1, 2, 3);

    Point3d point2;
    point2.setValues(1, 2, 3);

    if (point1.isEqual(point2)) {
        std::cout << "point1 and point2 are equal\n";
    } else {
        std::cout << "point1 and point2 are not equal\n";
    }

    Point3d point3;
    point3.setValues(3, 4, 5);

    if (point1.isEqual(point3)) {
        std::cout << "point1 and point3 are equal\n";
    } else {
        std::cout << "point1 and point3 are not equal\n";
    }

    return 0;

}
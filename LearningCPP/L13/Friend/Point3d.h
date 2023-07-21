//
// Created by User on 21/07/2023.
//

#ifndef REPLITREPO_POINT3D_H
#define REPLITREPO_POINT3D_H

class Vector3d;

class Point3d {
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Point3d(double x = 0.0, double y = 0.0, double z = 0.0);

    void print() const;

    void moveByVector(const Vector3d& v);
};


#endif //REPLITREPO_POINT3D_H

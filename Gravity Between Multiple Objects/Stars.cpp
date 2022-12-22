#include <iostream>

#include "Stars.h"

using namespace std;


Point::Point(int xx, int yy, int zz)
{
    x = xx;
    y = yy;
    z = zz;
}
void Point::set_coordinates()
{
    cout << "Set coordinates for: " << endl;
    cout << "x: ";
    cin >> x;
    cout << "y: ";
    cin >> y;
    cout << "z: ";
    cin >> z;
}
void Point::show_coordinates()
{
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
}




Star::Star(int xx, int yy, int zz, int m)
:Point::Point(xx,yy,zz)
{
    x = xx;
    y = yy;
    z = zz;
    mass = m;
}
void Star::set_mass()
{
    cout << "Set mass: ";
    cin >> mass;
}
void Star::show_mass()
{
    cout << "mass is " << mass << endl;
}




Vector::Vector(int xx, int yy, int zz, long double vx, long double vy, long double vz, long double forcx, long double forcy, long double forcz, long double force1)
:Point::Point(xx,yy,zz)
{
    x = xx;
    y = yy;
    z = zz;

    vector_x = vx;
    vector_y = vy;
    vector_z = vz;

    force_x = forcx;
    force_y = forcy;
    force_z = forcz;

    force = force1;

}
    void Vector::show_vector()
    {
        cout << "Vector point: (" << x << ", " << y << ", " << z << ")."<< endl;
        cout << "Vector direction: (" << vector_x << ", " << vector_y << ", " << vector_z << ")."<< endl;
        cout << "Force of the vector is: " << force << endl;
    }
    void Vector::set_vector(int a,int b,int c,long double d,long double e,long double f, long double g, long double h, long double k, long double l)
    {
        x = a;
        y = b;
        z = c;

        vector_x = d;
        vector_y = e;
        vector_z = f;

        force_x = g;
        force_y = h;
        force_z = k;

        force = l;

    }


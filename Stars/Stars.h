#include <iostream>


using namespace std;

class Point
{
public:
    friend class Star;
    friend class Vector;
    float x, y, z;


    Point(int = (rand()%10000 - 5000), int = (rand()%10000 - 5000), int = (rand()%00000 - 5000));
    void set_coordinates();
    void show_coordinates();
};



class Star : public Point
{
public:

    float mass;

    Star(int = (rand()%10000 - 5000), int = (rand()%10000 - 5000), int = (rand()%10000 - 5000), int = (rand()%10000));

    void set_mass();
    void show_mass();

};


class Vector : public Point
{
public:

    float vector_x, vector_y, vector_z;
    float force_x, force_y, force_z;
    float force;

    Vector(int = 0, int = 0, int = 0, float = 0, float = 0, float = 0, float = 0, float = 0, float = 0, float = 0);

    void show_vector();
    void set_vector(int,int,int,float,float,float,float,float,float, float);





};


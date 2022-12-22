#include <iostream>


using namespace std;

class Point
{
public:
    friend class Star;
    friend class Vector;
    long double x, y, z;


    Point(int = (rand()%10000 - 5000), int = (rand()%10000 - 5000), int = (rand()%00000 - 5000));
    void set_coordinates();
    void show_coordinates();
};



class Star : public Point
{
public:

    long double mass;

    Star(int = (rand()%10000 * 1000 + rand()%1000 - 5000000), int = (rand()%10000 * 1000 + rand()%1000 - 5000000),
         int = (rand()%10000 * 1000 + rand()%1000 - 5000000), int = (rand()%10000 * 1000 + rand()%1000));         //rand doesn't seem to be capable of randomizing
                                                                                                                  //from greater values than 10,000 or so

    void set_mass();
    void show_mass();

};


class Vector : public Point
{
public:

    long double vector_x, vector_y, vector_z;
    long double force_x, force_y, force_z;
    long double force;

    Vector(int = 0, int = 0, int = 0, long double = 0, long double = 0, long double = 0, long double = 0, long double = 0, long double = 0, long double = 0);

    void show_vector();
    void set_vector(int,int,int,long double,long double,long double,long double,long double,long double, long double);





};


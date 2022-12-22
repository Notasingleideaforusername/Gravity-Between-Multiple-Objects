#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>


#include "Stars.h"

using namespace std;

int n;                                  //number of stars/vectors
char mode;
long double x,y,z,m = {0};              //sum of all points divided by mass
long double xm, ym, zm;           //coordinates of a central point
long double  G = 6.67 * pow(10,-11);       //constant G for gravity measure


int main()
{
cout << "How many stars?" << endl;
cin >> n;                                  //set 'n' - number of objects

srand (time(NULL));                     //start randomizing - required for most constructors

Star s[n];

cout << "Press r to randomize or s to set values." << endl;
cin >> mode;

switch (mode)
{
case 's':
    for (int i = 0; i < n; i++)
    {
        cout << "Set values for object nr. " << i+1 << endl;
        s[i].set_coordinates();
        s[i].set_mass();
        cout << "--------------------------------------------------------------" << endl;
    }
    break;
case 'r':
    {
        ;
    }
    break;
default:
    {
        cout << "Unknown command" << endl;
        return 0;
    }
}


for(int i = 0; i<n; i++)                        //starts here
{
    x = x + (s[i].x * s[i].mass);
    y = y + (s[i].y * s[i].mass);
    z = z + (s[i].z * s[i].mass);               //      calculates central point of all mass in the system
    m = m + s[i].mass;
}

    xm = x/m;
    ym = y/m;
    zm = z/m;                                    //ends here


long double distance[n];                      //create arrays outside of class - preferred, otherwise constructors could get complicated

for(int i = 0; i<n; i++)
{
   distance[i] = sqrt(pow(s[i].x - xm,2.0) + pow(s[i].y - ym,2.0) + pow(s[i].z - zm,2.0));     //calculate difference in x,y,z from barycenter, then diagonal of thus created body                                  //gravity from F = G*m1*m2/r2 formula
}


for(int i = 0; i < n; i++)                     //print
{
   cout << "Star " << i+1 << ":" << endl;
   s[i].show_coordinates();
   s[i].show_mass();
   cout << "Distance of point " << i+1 << " to the central point of mass is: " << distance[i] << "km" << endl;
   cout << "--------------------------------------------------------------" << endl;
}

cout << "Central point of all mass is: " <<"(" << xm << ", " << ym << ", " << zm << ")" << endl;;
cout << "All mass is: " << m << "kg" << endl;

long double tab_vector[n][n][3];                   //array of basic vectors for any two objects in the system for each axis
long double tab_force[n][n][3];                    //array of basic forces for any two objects in the system for each axis
long double tab_distance[n][n];                    //array of distance between any two objects in the system (needed for force calculations)

for(int i = 0; i < n; i++)
{
    for(int j = 0; j < n; j++)
    {
        if(i != j)
        {
            tab_distance[i][j] = sqrt(pow((s[i].x - s[j].x),2.0) + pow((s[i].y - s[j].y),2.0) + pow((s[i].z - s[j].z),2.0));     //calculate distance from sqrt(x^2 + y^2 + z^2)
            // cout << "distance is: " << tab_distance[i][j] << endl;
            if(tab_distance[i][j] != 0)
            {
                tab_vector[i][j][0] = (s[j].x - s[i].x);
                // cout << "Vector x for " << i + 1 << " to " << j + 1 << " is: " << tab_vector[i][j][0] << endl;
                tab_vector[i][j][1] = (s[j].y - s[i].y);
                // cout << "Vector y for " << i + 1 << " to " << j + 1 << " is: " << tab_vector[i][j][1] << endl;
                tab_vector[i][j][2] = (s[j].z - s[i].z);
                // cout << "Vector z for " << i + 1 << " to " << j + 1 << " is: " << tab_vector[i][j][2] << endl;

                tab_force[i][j][0] = (G * s[i].mass * s[j].mass)/pow(tab_distance[i][j],3.0) * abs(tab_vector[i][j][0]);        //force for each axis
                // cout << "Force of " << i + 1 << " on " << j + 1 << " in the x axis is: " << tab_force[i][j][0] << endl;
                tab_force[i][j][1] = (G * s[i].mass * s[j].mass)/pow(tab_distance[i][j],3.0) * abs(tab_vector[i][j][1]);
                // cout << "Force of " << i + 1 << " on " << j + 1 << " in the y axis is: " << tab_force[i][j][1] << endl;
                tab_force[i][j][2] = (G * s[i].mass * s[j].mass)/pow(tab_distance[i][j],3.0) * abs(tab_vector[i][j][2]);
                // cout << "Force of " << i + 1 << " on " << j + 1 << " in the z axis is: " << tab_force[i][j][2] << endl;

                tab_vector[i][j][0] *=  tab_force[i][j][0];
                tab_vector[i][j][1] *=  tab_force[i][j][1];
                tab_vector[i][j][2] *=  tab_force[i][j][2];


            }
        }
    }
}

Vector v[n];                                               //create new objects from class 'Vector'

for(int i = 0; i < n; i++)
{
    for(int j = 0; j < n; j++)
    {
        if(i != j)
        {
            v[i].vector_x += tab_vector[i][j][0];          //add little vectors to the big one
            v[i].vector_y += tab_vector[i][j][1];
            v[i].vector_z += tab_vector[i][j][2];

            v[i].force_x += tab_force[i][j][0];             //same with forces
            v[i].force_y += tab_force[i][j][1];
            v[i].force_z += tab_force[i][j][2];
        }
    }
    v[i].x = s[i].x;
    v[i].y = s[i].y;
    v[i].z = s[i].z;

    v[i].force = sqrt(pow(v[i].force_x, 2.0) + pow(v[i].force_y, 2.0) + pow(v[i].force_z, 2.0));     //once the forces are added calculate their sum
    cout << "--------------------------------------------------------------" << endl;
    cout << "Vector " << i+1 << ": " << endl;

    v[i].show_vector();                                   //print vectors
}
cout << "--------------------------------------------------------------" << endl;


//Two things that could be added are:
//Something better than cout-ing it on the prompt (a proper body that would show all the points in the space, with vectors as arrows)
//vectors here are stupid as fuck - they don't take into consideration strength, only direction, which leads to wrong numbers.


    return 0;
}

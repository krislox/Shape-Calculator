//
//  Purpose: prompts the user to enter a rectangle's length and width, a circle's circumference, a
//  square's side length, and 3 sides of a triangle, then shows the area, circumference and perimeter of
//  those shapes and the volume and surface area for a sphere
//
//
//
//
//  Created by Van Ralf Aguas on 3/12/14.
//  Copyright (c) 2014 Van Ralf Aguas. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
public:
    void print_area(void);
    void print_perimeter(void);
    virtual float calc_area(void);
    virtual float calc_perimeter(void);
};

void Shape::print_area()
{ cout << calc_area(); }

void Shape::print_perimeter()
{ cout << calc_perimeter();}

float Shape::calc_area()
{ return -1; }

float Shape::calc_perimeter()
{ return -1;}

// Circle **************** Circle **************** Circle

class Circle: public Shape
{
protected:
    float radius;
public:
    void store_radius(float);
    float return_radius();
    float calc_perimeter();
    float calc_area();
};

void Circle::store_radius(float value)
{ radius = value;}

float Circle::return_radius()
{return radius;}

float Circle::calc_area()
{return 3.14 * radius * radius;}

float Circle::calc_perimeter()
{return 2 * 3.14 * radius;}

class Sphere:public Circle
{
public:
    float calc_volume();
    float calc_s_area();
};

// Sphere ***************** Sphere ***************** Sphere

float Sphere::calc_volume()
{
    float sphere_vol = 3.14 * radius *radius * radius * (4 / 3);
    return sphere_vol;
}

float Sphere::calc_s_area()
{
    float sphere_area = 4 * 3.14 * radius * radius;
    return sphere_area;
}

// Triangle ************** Triangle **************** Triangle

class Triangle: public Shape
{
private:
    double leg1, leg2, leg3;
    double heron_form;
public:
    void store_leg_1(double);
    void store_leg_2(double);
    void store_leg_3(double);
    double return_leg_val1(void);
    double return_leg_val2(void);
    double return_leg_val3(void);
    float calc_area(void);
    float calc_perimeter(void);
};

void Triangle::store_leg_1 (double value1)
{   leg1 = value1;   }
void Triangle::store_leg_2 (double value2)
{   leg2 = value2;   }
void Triangle::store_leg_3 (double value3)
{   leg3 = value3;   }

double Triangle::return_leg_val1 (void)
{   return leg1;   }
double Triangle::return_leg_val2 (void)
{   return leg2;   }
double Triangle::return_leg_val3 (void)
{   return leg3;   }

float Triangle::calc_area(void)
{
    double heron_val= (leg1 + leg2 + leg3) / 2;
    heron_form = heron_val * (heron_val - leg1)
    * (heron_val - leg2)
    * (heron_val - leg3);
    heron_form = sqrt(heron_form);
    return heron_form;
}

float Triangle::calc_perimeter(void)
{
    return leg1 + leg2 + leg3;
}

//Rectangle ************** Rectangle *************** Rectangle

class Rectangle:public Shape
{
protected:
    float length;
    float width;
public:
    void store_length(float);
    void store_width(float);
    float return_length();
    float return_width();
    float calc_area();
    float calc_perimeter();
};

void Rectangle::store_length(float length_val)
{ length = length_val;}

void Rectangle::store_width(float width_val)
{ width = width_val;}

float Rectangle::return_length()
{ return length;}

float Rectangle::return_width()
{ return width;}

float Rectangle::calc_area()
{ return length * width;}

float Rectangle::calc_perimeter()
{ return (2 * length) + (2 * width);}

// Square *************** Square ******************* Square

class Square:public Rectangle
{
protected:
    float side;
public:
    float calc_area();
    float calc_perimeter();
};

float Square::calc_area()
{ return length * length ;}

float Square::calc_perimeter()
{ return 4 * length;}

// Main ******************* Main ****************** Main ******

int main()
{
    float x,y,z;
    Rectangle rec;
    Square sqr;
    Circle cir;
    Triangle tri;
    Sphere sph;
    
    cout << "Input Rectangle length" << endl;
    cin >> x;
    rec.store_length(x);
    cout << "Input Rectangle width" << endl;
    cin >> y;
    rec.store_width(y);
    cout << "The length is: " << x << "\n"
    << "The width is: " << y << endl;
    cout << "Rectangle's area is: " ;
    rec.print_area();
    cout << endl;
    cout << "Rectangle's perimeter is: ";
    rec.print_perimeter();
    cout << endl;
    
    cout << "Input Circle radius" << endl;
    cin >> z;
    cir.store_radius(z);
    cout << "The radius is: " << z << "\n"
    << "The area is: ";
    cir.print_area();
    cout << endl;
    cout << "The circumference is: ";
    cir.print_perimeter();
    cout << endl;
    
    cout << "Input Sphere radius" << endl;
    cin >> z;
    sph.store_radius(z);
    cout << "The radius is: " << z << "\n"
    << "The surface area is: " << sph.calc_s_area() << "\n"
    << "The volume is: " << sph.calc_volume() << endl;
    
    cout << "Input Square side length" << endl;
    cin >> x;
    sqr.store_length(x);
    cout << "The side length is: " << x << "\n"
    << "The area is: ";
    sqr.print_area();
    cout << endl;
    cout << "The perimeter is: ";
    sqr.print_perimeter();
    cout << endl;
    
    cout << "For a triangle, please enter the value of the three sides" << endl;
    cin >> x >> y >> z;
    tri.store_leg_1(x);
    tri.store_leg_2(y);
    tri.store_leg_3(z);
    
    cout << "The area of the triangle is: ";
    tri.print_area();
    cout << endl;
    cout << "The perimeter of the triangle is: ";
    tri.print_perimeter();
    cout << endl;
    
}

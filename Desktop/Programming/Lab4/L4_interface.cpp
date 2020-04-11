#include <iostream>
#include "interface.h"
#include <cmath>

Circle::Circle(){
    centre = {0, 0};
    r = 0;
    mass_ = 0;
    position_ = {0, 0};

}

Circle::Circle(const Point &centre_, const double &r_, const double &mass__, const CVector2D &position__)
{
    centre = centre_;
    r = r_;
    mass_ = mass__;
    position_ = position__;
}

Circle::Circle(const Circle &obj){
    centre = obj.centre;
    r = obj.r;
    mass_ = obj.mass_;
    position_ = obj.position_;
}

void Circle::initFromDialog(){
    std::cout << "input coordinate of centre: ";
    centre.initFromDialog();
    std::cout << "input radius: ";
    std::cin >> r;
    std::cout << "input mass: ";
    std::cin >> mass_;
    std::cout << "input position: first point: ";
    position_.A.initFromDialog();
    std::cout << "input position: second point: ";
    position_.B.initFromDialog();

}

double Circle::square() const {
    return M_PI * pow(r, 2);
}

double Circle::perimeter () const {
    return 2 * M_PI * r;
}

void Circle::draw() const {
    std::cout << "Centre of circle" << std::endl;
    centre.printCoordinate();
    std::cout << "The Radius is " << r << std::endl;
    std::cout << "The mass is " << mass_ << std::endl;
    std::cout << "The position is ";
    position_.PrintVector();

}

unsigned int Circle::size() const  {
    return sizeof(*this);
}

double Circle::mass() const  {
    return mass_;
}

CVector2D Circle::position() const  {
    return position_;

}

const char* Circle::classname() const {
    return "Circle";
}

bool Circle::operator == (const IPhysObject &obj) const {
    return this->mass() == obj.mass();
}

bool Circle::operator < (const IPhysObject &obj) const {
    return this->mass() < obj.mass();
}

//Triangle

EquilateralTriangle::EquilateralTriangle(){
    A = {0, 0};
    B = {0, 0};
    C = {0, 0};
    mass_ = 0;
    position_ = {0, 0};

}

EquilateralTriangle::EquilateralTriangle(const Point &a, const Point &b, const Point &c,const double &mass__, const CVector2D &position__)
{
    A = a;
    B = b;
    C = c;
    mass_ = mass__;
    position_ = position__;
}

EquilateralTriangle::EquilateralTriangle(const EquilateralTriangle &obj){
    A = obj.A;
    B = obj.B;
    C = obj.C;
    mass_ = obj.mass_;
    position_ = obj.position_;
}

void EquilateralTriangle::initFromDialog () {
    std::cout << "Input the coordinate of equilateral Triangle ABC" << std::endl;
    std::cout << "Point A: " << std::endl;
    A.initFromDialog();
    std::cout << "Point B: " << std::endl;
    B.initFromDialog();
    std::cout << "Point C: " << std::endl;
    C.initFromDialog();
    std::cout << "mass: " << std::endl;
    std::cin >> mass_;
    std::cout << "position: firs point: ";
    position_.A.initFromDialog();
    std::cout << " second point: ";
    position_.B.initFromDialog();
    std::cout << std::endl;
}


double EquilateralTriangle::square () const  {
    return (pow(AB.lenghtVector(), 2) * sqrt(3))/4;
}

double EquilateralTriangle::perimeter () const  {
    return AB.lenghtVector() * 3;
}

void EquilateralTriangle::draw () const {
    std::cout << "The point A: " << std::endl;
    A.printCoordinate();
    std::cout << "The point B: " << std::endl;
    B.printCoordinate();
    std::cout << "The point C: " << std::endl;
    C.printCoordinate();
    std::cout << "The mass: " << mass() << std::endl;
    std::cout << "The position: ";
    position_.PrintVector();
}

unsigned int EquilateralTriangle::size() const  {
    return sizeof(*this);
}

double EquilateralTriangle::mass() const  {
    return mass_;
}

CVector2D EquilateralTriangle::position () const  {
    return position_;
}

const char* EquilateralTriangle::classname() const {
    return "Equral triangle";
}

bool EquilateralTriangle::operator == (const IPhysObject &obj) const {
    return this->mass() == obj.mass();
}
bool EquilateralTriangle::operator < (const IPhysObject &obj) const {
    return this->mass() < obj.mass();
}


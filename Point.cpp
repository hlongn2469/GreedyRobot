//Point.cpp
//CSS 342 Program2
//Implemented by_ Kray_ Nguy_en on 11/2/2020
#include "Point.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Point::~Point(){

}

Point::Point(){
	this -> x_ = 0;
	this -> y_ = 0;
}

Point::Point(int x_, int y_){
	this -> x_ = x_;
	this -> y_ = y_;
}

int Point::getX(){
	return x_;
}

int Point::getY(){
    return y_;
}


bool Point::setCoordinates(int x_, int y_){
	this -> x_ = x_;
    this -> y_ = y_;
	return true;
}

Point Point::operator+(const Point &other) const{
	Point retVal = *this;
	retVal.x_ += other.x_;
    retVal.y_ += other.y_;
	return retVal;
}

Point Point::operator-(const Point &other) const{
	Point retVal = *this;
	retVal.x_ -= other.x_;
    retVal.y_ -= other.y_;
	return retVal;
}

bool Point::operator==(const Point &other) const{
	return ((this -> x_ == other.x_) && (this -> y_ == other.y_));
}

bool Point::operator!=(const Point &other) const{
    return ((this -> x_ != other.x_) || (this -> y_ != other.y_));
}

ostream& operator<<(ostream &outStream, const Point &other){
	outStream << "(" << other.x_ << ", " << other.y_ << ")";
	return outStream;
}
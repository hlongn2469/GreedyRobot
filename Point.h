//Point.h
//CSS 342 Program2
//Implemented by Kray Nguyen on 11/2/2020
#ifndef P
#define P
#include <string>
using namespace std;

// The class models the (x,y) point coordinates 
class Point {
public:
    // constructor-destructor
    Point();
    Point(int x_, int y_);
    ~Point();

    // getters-setters
    int getX();
    int getY();
    bool setCoordinates(int x_, int y_);

    // simple operator overload
    Point operator+(const Point &other) const;    
    Point operator-(const Point &other) const; 
    bool operator==(const Point &other) const;    
    bool operator!=(const Point &other) const; 
    friend ostream& operator<<(ostream &, const Point & other);

private:
    int x_;
    int y_;
};

#endif

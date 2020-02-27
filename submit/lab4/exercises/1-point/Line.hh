#ifndef "POINT_HH_"

#include <cmath>
#include <string>
#include <sstream>

class Line{
	Point p1;
	Point p2;
	
}


void Line::lenght(const Point& other) const {
  	const auto dx = x - other.x;
  	const auto dy = y - other.y;
 	return sqrt(dx*dx + dy*dy);

}	
std::string Point::toString() const {
  
  std::stringstream s;
  s << "(" << x << ", " << y << ")";
  return s.str(); 
}


};

#endif //ifndef POINT_HH_



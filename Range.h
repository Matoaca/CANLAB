#include "Packet.h"

struct Range{
	Point top;
	Point bottom;
	string toString();

	Range split();
	bool inside(Point p) { return to <= p && p < bottom; }
	bool contains(Point p) { return top <= p && p < bottom; }
	bool borders(Range r);
	Range inverse();

	Point midpoint() { return (top + bottom)/2; }
	string toString() { return "top : " + to_String() + "\n bottom : " + bottom.to_Sting(); }
};

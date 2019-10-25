#include <string>
#include <cmath>

struct Point{
    float x;
    float y;

	Point();
	~Point();

    bool operator <(const Point&rhs) { return (x < rhs.x && y < rhs.y); }
    bool operator >=(const Point&rhs) { return !(*this < rhs); }
    bool operator <=(const Point&rhs) { return (x <= rhs.x && y <= rhs.y); }

    Point operator /(float d) { return Point(x/d, y/d); }
    Point operator +(const Point& rhs) { return Point(x + rhs.a, y + rhs.b); }

//    string toString() { return "{" + to_String(x) + ", " + ", " + to_String(y) + "}"; }
    float distance(Point p) { return sqrt((x-p.x) * (x-p.x) + (y - p.y) * (y - p.y)); }

};

enum MsgType{
	Joinrequest,
	Joinresponse,
	PEEP_UPDATE
};

struct Address{
	int port;
	char host[64];
};

struct Packet{
    MsgType type;
	Address src;
	Address dest;
    unsigned char payload[60];
};

struct Msg{
    int size;
    char buffer[56];
};

struct Joinrequest{
	Point dest;
	int host;
	int port;
};

struct Joinresponse{
	Point top;
	Point left;
};



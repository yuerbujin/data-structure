#ifndef _MYPOINT_H_
#define _MYPOINT_H_ 

typedef struct Point Point;

struct Point{
	int x;
	int y;
	
	Point(int x1 = 0, int y1 = 0);
};

Point::Point(int x1, int y1): x(x1), y(y1)
{
	
}

#endif

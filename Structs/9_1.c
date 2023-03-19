#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point{
    float x,y;
} Point; //p1, p2;

void printPoint(Point p);
Point createPoint(double x, double y);
double getDistance(Point a, Point b);

int main(void)
{
    //Point p1, p2;
   // p1 = createPoint(2.0, -3.0);
   // p2 = createPoint(-4.0, 5.0);
    double result = getDistance(createPoint(2.0, -3.0), createPoint(-4.0, 5.0));
    //printPoint(p1);
    //printPoint(p2);
    printf("%.2f", result);
}

void printPoint(Point p)
{
    printf("%.2f , %.2f\n", p.x, p.y);
}

Point createPoint(double x, double y)
{
    Point p = {x,y};

    return p;
}

double getDistance(Point a, Point b)
{
    return sqrt(pow(a.x - b.x,2) + pow(a.y - b.y,2));
}

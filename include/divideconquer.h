#ifndef DIVIDECONQUER_H
#define DIVIDECONQUER_H
#include "create.h"
#include <vector>

class Divideconquer
{
public:
    Divideconquer(int n);
    ~Divideconquer();

private:
    double distance(const Point &i, const Point &j);
    bool compareX(const Point &i, const Point &j);
    double recursive_closest_pair(std::vector<Point> &points, int n);
};

#endif
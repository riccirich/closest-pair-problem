#ifndef DIVIDECONQUER_H
#define DIVIDECONQUER_H
#include "create.h"
#include <vector>

class Divideconquer
{
public:
    Divideconquer(int n);
    ~Divideconquer();
    long double runtime;
    double closest_pair_distance;

private:
    double distance(const Point &i, const Point &j);
    double recursive_closest_pair(std::vector<Point> &points, int n);
};

#endif
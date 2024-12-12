#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H
#include "create.h"

class Bruteforce
{
public:
    Bruteforce(int n);
    ~Bruteforce();
    long double runtime;
    double closest_pair_distance;

private:
    double distance(const Point &i, const Point &j);
};

#endif
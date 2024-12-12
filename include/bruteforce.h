#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H
#include "create.h"

class Bruteforce
{
public:
    Bruteforce(int n);
    ~Bruteforce();

private:
    double distance(const Point &i, const Point &j);
};

#endif
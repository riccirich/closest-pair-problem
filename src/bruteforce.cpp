#include "../include/bruteforce.h"
#include "../include/create.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <chrono>

Bruteforce::Bruteforce(int n)
{
    std::vector<Point> points;
    Point p;
    std::string filename = "output" + std::to_string(n) + ".txt";
    std::ifstream input_file(filename);

    while (input_file >> p.x >> p.y)
    {
        points.push_back(p);
    }

    auto start = std::chrono::high_resolution_clock::now();

    double minimum_distance = std::numeric_limits<double>::max();
    Point p1, p2;

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i + 1; j < n; j++)
        {
            double dist = distance(points[i], points[j]);
            if (dist < minimum_distance)
            {
                minimum_distance = dist;
                p1 = points[i];
                p2 = points[j];
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> elapsed = end - start;

    std::cout << "Closest pair: (" << p1.x << ", " << p1.y << ") and ("
              << p2.x << ", " << p2.y << ") with distance " << minimum_distance << "\n";

    std::cout << "Time taken: " << elapsed.count() << " microseconds\n";
}

Bruteforce::~Bruteforce()
{
}

double Bruteforce::distance(const Point &i, const Point &j)
{
    return sqrt(pow(i.x - j.x, 2) + pow(i.y - j.y, 2));
}
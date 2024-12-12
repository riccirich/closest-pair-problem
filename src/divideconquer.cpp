#include "../include/divideconquer.h"
#include "../include/create.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <chrono>
#include <algorithm>

Divideconquer::Divideconquer(int n)
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

    std::sort(points.begin(), points.end(), [](Point const &a, Point const &b) -> bool
              { return a.x < b.x; });

    double minimum_distance = recursive_closest_pair(points, n);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> elapsed = end - start;

    std::cout << "The shortest distance is: " << minimum_distance << "\n";
    std::cout << "Time taken: " << elapsed.count() << " microseconds\n";
}

Divideconquer::~Divideconquer()
{
}

double Divideconquer::distance(const Point &i, const Point &j)
{
    return sqrt(pow(i.x - j.x, 2) + pow(i.y - j.y, 2));
}

double Divideconquer::recursive_closest_pair(std::vector<Point> &points, int n)
{
    if (n <= 3)
    {
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

        return minimum_distance;
    }

    int mid = n / 2;
    Point mid_point = points[mid];

    std::vector<Point> left_points(points.begin(), points.begin() + mid);
    std::vector<Point> right_points(points.begin() + mid, points.end());

    double left_distance = recursive_closest_pair(left_points, mid);
    double right_distance = recursive_closest_pair(right_points, n - mid);

    double delta = std::min(left_distance, right_distance);

    std::vector<Point> strip;
    for (size_t i = 0; i < n; i++)
    {
        if (abs(points[i].x - mid_point.x) < delta)
        {
            strip.push_back(points[i]);
        }
    }

    double strip_distance = std::numeric_limits<double>::max();
    for (size_t i = 0; i < strip.size(); i++)
    {
        for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < delta; j++)
        {
            double dist = distance(strip[i], strip[j]);
            if (dist < strip_distance)
            {
                strip_distance = dist;
            }
        }
    }

    return std::min(delta, strip_distance);
}
#include "./src/create.cc"
#include "./src/bruteforce.cpp"
#include "./src/divideconquer.cpp"
#include <iostream>

void start_tests(int number_of_points, int number_of_tests);

int main()
{
    int points, tests;
    std::cout << "Enter the number of points to generate: ";
    std::cin >> points;
    std::cout << "Enter the number of tests to run: ";
    std::cin >> tests;
    start_tests(points, tests);
    return 0;
}

void start_tests(int number_of_points, int number_of_tests)
{
    long double bruteforce_sumtotal = 0;
    long double divideconquer_sumtotal = 0;
    double bruteforce_closest_pair_distance;
    double divideconquer_closest_pair_distance;

    Create create(number_of_points);

    std::cout << "\nBruteforce Solution: ";
    for (int i = 0; i < number_of_tests; i++)
    {
        Bruteforce B(number_of_points);
        bruteforce_sumtotal += B.runtime;
        bruteforce_closest_pair_distance = B.closest_pair_distance;
    }
    long double bruteforce_average_runtime = bruteforce_sumtotal / number_of_tests;
    std::cout << bruteforce_average_runtime << " microseconds\n";
    std::cout << "Closest Pair Distance: " << bruteforce_closest_pair_distance << "\n";

    std::cout << "Divide-and-Conquer Solution: ";
    for (int i = 0; i < number_of_tests; i++)
    {
        Divideconquer D(number_of_points);
        divideconquer_sumtotal += D.runtime;
        divideconquer_closest_pair_distance = D.closest_pair_distance;
    }
    long double divideconquer_average_runtime = divideconquer_sumtotal / number_of_tests;
    std::cout << divideconquer_average_runtime << " microseconds\n";
    std::cout << "Closest Pair Distance: " << divideconquer_closest_pair_distance << "\n";
}
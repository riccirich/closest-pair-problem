#include "../include/create.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

Create::Create(int n)
{
    std::string filename = "output" + std::to_string(n) + ".txt";
    std::ofstream output_file(filename);

    // Seed the random number generator
    std::srand(std::time(nullptr));

    for (int i = 0; i < n; ++i)
    {
        // Generate random x and y coordinates between -10000 and 10000
        int x = std::rand() % 20001 - 10000;
        int y = std::rand() % 20001 - 10000;

        output_file << x << " " << y << std::endl;
    }

    output_file.close();
}

Create::~Create()
{
}
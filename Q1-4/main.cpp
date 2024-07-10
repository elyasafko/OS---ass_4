#include "graph.hpp"
#include <iostream>
#include <stdexcept>

// Function to run test cases
void test(Graph &g)
{
    int res = g.isEulerian();
    if (res == 2)
    {
        std::cout << "Graph has an Euler cycle\n";
    }
    else
    {
        std::cout << "Graph does not have an Euler cycle\n";
    }
}

int main(int argc, char const *argv[])
{
    if (argc != 4)
    {
        std::cerr << "Invalid number of arguments. Usage: <program> <edges> <vertices> <random_seed>\n";
        return 1;
    }

    try
    {
        int edges = std::stoi(argv[1]);
        int vertices = std::stoi(argv[2]);
        int random_seed = std::stoi(argv[3]);

        Graph g(edges, vertices, random_seed);
        test(g);
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Invalid argument: Please provide valid integers for edges, vertices, and random_seed.\n";
        return 1;
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Argument out of range: Please provide smaller integer values.\n";
        return 1;
    }

    return 0;
}

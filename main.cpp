#include <iostream>
#include "BackpackProblem.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    BackpackProblem bp({ {2, 4}, {3, 5}, {1, 3} }, 3);
    int dynamicResult = bp.dynamic_solution();
    int greedyResult = bp.greedy_solution();
    std::cout << "Dynamiczne (po 1 przedmiocie) : " << dynamicResult << std::endl;
    std::cout << "Zachłanne : " << greedyResult << std::endl;
    return 0;
}

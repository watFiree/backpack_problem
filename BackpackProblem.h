#ifndef BACKPACKPROBLEM_H
#define BACKPACKPROBLEM_H

#include <vector>

class BackpackProblem {
    std::vector<std::pair<int, int>> items; // tablica wartosci [waga, wartosc]
    int backpackSize;
    int size;
    static bool compareItems(std::pair<int, int> item1, std::pair<int, int> item2);
public:
    BackpackProblem(std::vector<std::pair<int, int>> items, int backpackSize);
    int dynamic_solution();
    int greedy_solution();
};


#endif

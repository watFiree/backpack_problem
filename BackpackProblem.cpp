#include "BackpackProblem.h"
#include <vector>

BackpackProblem::BackpackProblem(std::vector<std::pair<int, int>> items, int backpackSize) {
    this->items = items;
    this->backpackSize = backpackSize;
    this->size = items.size();
}

int BackpackProblem::dynamic_solution() {
    std::vector<std::vector<int>> Q(size+1, std::vector<int>(backpackSize+1, 0));

    for(int i = 1; i <= size; i++) {
        for(int j = 1; j <= backpackSize; j++) {
            int weight = items[i-1].first;
            int value = items[i-1].second;
            if(weight > j) {
                Q[i][j] = Q[i-1][j];
            } else {
                Q[i][j] = std::max(Q[i-1][j], Q[i-1][j-weight] + value);
            }
        }
    }

    return Q[size][backpackSize];
}



int BackpackProblem::greedy_solution() {
    std::vector<std::pair<int, double>> sortedItems;
    for(int i = 0; i < size; i++) {
        double profitability = double(items[i].second)/double(items[i].first);
        sortedItems.emplace_back(i, profitability);
    }

    std::sort(sortedItems.begin(), sortedItems.end(), BackpackProblem::compareItems);

    int value = 0, weight = 0;
    for(std::pair<int, int> r : sortedItems) {
        int index = r.first;
        while (weight + items[index].first <= backpackSize) {
            weight += items[index].first;
            value += items[index].second;
        }
    }

    return value;
}

bool BackpackProblem::compareItems(std::pair<int, int> item1, std::pair<int, int> item2) {
    return item1.second > item2.second;
}

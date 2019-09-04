#include <random>
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    int size;
    std::cout << "Vpisi velikost seznama: ";
    std::cin >> size;
    std::vector<int> every(size);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(-100, 100);

    for (auto& element: every) {
        element = dist(gen);
    }

    std::cout << std::accumulate(every.begin(), every.end(), 0.0)/every.size();
}

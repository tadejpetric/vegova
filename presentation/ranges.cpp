#include <vector>
#include <iostream>
int main() {
    std::vector<int> a {1, 2, 3, 4};
    for (int x: a) { std::cout << x << " "; }
    std::cout << "\n";
    for (auto&& x: a)
        ++x;
    for (const auto& x: a)
        std::cout << x << " ";
}

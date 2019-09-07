#include <iostream>
#include <vector>

template <typename... Args>
void square(Args... args) {
    auto sqf = [](int i) {std::cout << i;};
    (sqf(args), ...);
}

int main() {
    square(1,2,3,4,5);
}

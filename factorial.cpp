#include <iostream>

template <int n>
struct fact {
    enum { val = n * fact<n-1>::val };
};

template <>
struct fact<0> {
    enum { val = 1};
};

int main() {
    std::cout << fact<5>::val << "\n";
}

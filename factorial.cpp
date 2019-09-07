#include <iostream>

template <int n>
struct fact {
    enum { val = n * fact<n-1>::val };
};

template <>
struct fact<0> {
    enum { val = 1};
};

// modern constexpr
template <int n>
struct fact_ce {
    static constexpr uint64_t val = n * fact_ce<n-1>::val;
};

template <>
struct fact_ce<0> {
    static constexpr uint64_t val = 1;
};
 

constexpr int fact_constexpr(const int a) {
    if(not a)
        return 1;
    return a * fact_constexpr(a - 1);
}

int main() {
    std::cout << fact<5>::val << "\n";
    std::cout << fact_ce<6>::val << "\n";
    std::cout << fact_constexpr(5) << "\n";
}

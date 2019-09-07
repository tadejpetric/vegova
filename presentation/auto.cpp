#include <utility>
auto f() -> std::pair<int, bool> {return {1, true};}
int main() {
    auto first_a = 3;
    int first_e = 3;

    auto second_a = 3ull;
    unsigned long long second_e = 3;

    auto [a, b] = f(); // C++17
}

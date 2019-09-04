#include <iostream>

// fold expression C++17
template <typename... T>
bool any(T... args) {
    return (... || args);
}


void print_all() {};
// variadic template
template <typename Head, typename... Tail>
void print_all(Head head, Tail... args) {
    std::cout << head << " ";
    print_all(args...);
}




int main() {
    print_all(
        any(false, false, false),
        any(false, true, false, false),
        any(true, true),
        "\n");
}

#include <iostream>
#include <array>
#include <algorithm> //for count_if
#include <functional> //for std::function

#include <cstddef> //for size_t

template <typename T, std::size_t Size>
int count_easy1(const std::array<T, Size>& arr, T el) {
    int ctr = 0;
    for (const auto& i: arr) {
        if (i == el)
            ++ctr;
    }
    return ctr;
}


template <typename T, std::size_t Size>
int count_easy2(const std::array<T, Size>& arr, T el) {
    int ctr = 0;
    for (const auto& i: arr) {
        if (el < i)
            ++ctr;
    }
    return ctr;
}

template <typename T, std::size_t Size>
int count_easy3(const std::array<T, Size>& arr, T el) {
    int ctr = 0;
    for (const auto& i: arr) {
        if (not (i % el))
            ++ctr;
    }
    return ctr;
}

//etc...

template <typename T, std::size_t Size, typename Fn>
int count_generic(const std::array<T, Size>& arr, Fn&& f) {
    int ctr = 0;
    for (const auto& i: arr) {
        if (f(i))
            ++ctr;
    }
    return ctr;
}

int main() {
    std::array<int, 10> arr{1,2,3,4,5,2,3,4,2,6};
    std::cout << count_easy1(arr, 3) << "\n";
    std::cout << count_easy2(arr, 3) << "\n";
    std::cout << count_easy3(arr, 3) << "\n";

    std::cout << "-------------\n";
    
    std::cout << count_generic(arr, [](int x){ return x == 3; }) << "\n";
    std::cout << count_generic(arr, [](int x){ return x < 3; }) << "\n";
    std::cout << count_generic(arr, [](int x){ return not (x % 3); }) << "\n";

    std::cout << "-------------\n";

    std::cout << std::count_if(arr.begin(), arr.end(), [](int x){ return x == 3; }) << "\n";
    std::cout << std::count_if(arr.begin(), arr.end(), [](int x){ return x < 3; }) << "\n";
    std::cout << std::count_if(arr.begin(), arr.end(), [](int x){ return not (x % 3); }) << "\n";

}

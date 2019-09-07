#include <algorithm>
#include <functional> // for std::greater
int main() {
    std::array<int, 5> arr = {2, 8, 3, 3, 6};
    std::sort(arr.begin(), arr.end(), std::greater<int>());

    auto adj = std::adjacent_find(arr.begin(), arr.end());
    arr[std::distance(arr.begin(), adj)]; // this is 3
    // if no adjacent, returns last element
}

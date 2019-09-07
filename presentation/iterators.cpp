#include <vector>
#include <iterator>
int main() {
    std::vector<int> arr {1, 2, 3, 4};
    // we could've used auto here
    std::vector<int>::iterator it = arr.begin();
    std::advance(it, 2);
    while (it != arr.end()) { *it; ++it;}
}

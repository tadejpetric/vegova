int main() {
    auto a = [](){};
    auto b = [](int x){return x+1;};
    b(6); // returns 7
    int num1 = 3; int num2 = 5;
    auto c = [=](auto x) { // auto lambda C++14
        return x + num1 + num2;};
    auto d = [x = [](int y){return y-2;}] (int y) {
        return x(5) + y;
    }; // capture init C++14
    auto e = [num1]() mutable -> int {++num1; return num1;};
}

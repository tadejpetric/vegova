
template <typename Head, typename... Tail>
Head f(Head&& x, Tail&&... y) {
    return x;
}

int main() {
    f(1,2,3,3,4,54,5,6,72); // -> 1
    f(2,1); // -> 2
}

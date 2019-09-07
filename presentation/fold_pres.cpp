//take any amout of arguments
template <typename... Args>
int sum(Args... args) {
    // apply binary operation + to all arguments
    // sum(1, 2, 3, 4, 5)
    // -> ((((1+2) +3) +4) +5)
    return (... + args);
}

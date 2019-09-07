template <typename Fn>
int apply_3(Fn&& f) {
    return f(3);
}
int main() {
    apply_3([](int x){ return x + 1;});
}

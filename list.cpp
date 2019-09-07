#include <iostream>
#include <memory>

template <typename T>
struct llist {
    T contents;
    std::unique_ptr<llist> next_el;

    llist(int len) {
        if (len - 1)
            next_el = std::make_unique<llist>(len - 1);
    }
};

// variadic
template <typename T, typename... Args>
void write(llist<T>& list, T head, Args...  tail) {
    list.contents = head;
    if (list.next_el) {
        write(*list.next_el, tail...);
    }
}
template <typename T>
void write(llist<T>&) {}

// forwarding and constexpr if
template <class T, class Head, class... Tail>
void write_forward(llist<T>& list, Head&& arg, Tail&&... args) {
    list.value = std::forward<Head>(arg);
    if constexpr (sizeof...(Tail) != 0)
        write(*list.next, std::forward<Tail>(args)...);
}

// folded lambda with capture
template <class T, class... Args>
void write_fold(llist<T>& list, Args&&... args) {
    auto f = [it = &list](auto&& arg) mutable {
        it->value = std::forward<decltype(arg)>(arg);
        it = it->next.get();
    };
    (f(args), ...);
}


template <typename T>
void print(llist<T>& list) {
    std::cout << list.contents << " ";
    if (list.next_el) {
        print(*list.next_el);
    }
}

// we don't need any deletes!
template <typename T>
void delete_element(llist<T>& list, int n) {
    if (n == 0) {
        list = std::move(*list.next_el);
        return;
    }
    --n;
    auto temp = &list;
    while (n) {
        temp = temp->next_el.get();
        --n;
    }
    temp->next_el = std::move(temp->next_el->next_el); // will segfault if beyond last.
}

int main() {
    llist<int> test(8);
    write(test, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    int temp = 1;
    print(test);
    while(temp) {
        std::cin >> temp;
        delete_element(test, temp);
        print(test);
    }
}

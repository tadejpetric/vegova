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

template <typename T>
void print(llist<T>& list) {
    std::cout << list.contents << " ";
    if (list.next_el) {
        print(*list.next_el);
    }
}

template <typename T>
void delete_element(llist<T>& list, int n) {
    if (not n) {
        list = std::move(*list.next_el);
        return;
    }
    --n;
    auto temp = &list;
    while (n) {
        if (temp->next_el) {
            temp = temp->next_el.get();
        }
        --n;
    }
    temp->next_el = std::move(temp->next_el->next_el);
}

int main() {
    llist<int> test(8);
    write(test, 1, 2, 3, 4, 5, 6, 7, 8);
    int temp = 1;
    while(temp) {
        std::cin >> temp;
        delete_element(test, temp);
        print(test);
    }
}

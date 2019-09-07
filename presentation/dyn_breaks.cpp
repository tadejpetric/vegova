int read_delete(int* p) {
    // do something with p
    delete p; // clean up
}
int main() {
    int* p = new int(5);
    read_delete(p);
    delete p; // clean up
}

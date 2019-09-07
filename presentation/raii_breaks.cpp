int main() {
    int* x = new int(5);
    {
        int* a = new int(3);
    } // a memory leaks
} // x memory leaks

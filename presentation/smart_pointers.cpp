#include <memory>
int main() {
    std::unique_ptr<int> a = std::make_unique<int>(3);
    {
        auto p = std::make_unique<int>(5);
    } // p pobriše za sabo
} // a pobriše za sabo

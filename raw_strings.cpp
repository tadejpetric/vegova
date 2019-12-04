#include <string>

int main() {
    std::string a = "Test\n123\trwq";
    std::string raw_a1 = R"(Test\n123\trwq)";
    std::string raw_a2 = R"raw(Test\n123\trwq)raw";
}

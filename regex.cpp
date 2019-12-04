#include <iostream>
#include <regex>
#include <string>
#include <optional> // since c++17

auto find_domain_in_email(std::string email)
    -> std::optional<std::string> {
    std::regex query(R"(.+@.+\.([a-zA-Z]+))");
    std::smatch match;
    std::regex_search(email, match, query);
    if (std::regex_search(email, match, query) && match.size() > 1) {
        return {match.str(1)}; // create an option type
    }
    return {}; // return none
}

int main() {
    std::string email;
    
    std::cout << "vnesi email: ";
    std::cin >> email;
    std::cout << find_domain_in_email(email).value_or("no domain found");
    email = "tadej.petric1@gmail.com asd.ba@gmail.com aseqw@asd.com";
    
    std::regex query(R"(.+?@.+?\.([a-zA-Z]+))");
    std::sregex_iterator xbegin(email.begin(), email.end(), query);
    std::sregex_iterator xend;

    for (auto i = xbegin; i != xend; ++i) {
        std::cout << i->str(1) << " ";
    }
}

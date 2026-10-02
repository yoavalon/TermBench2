cpp
#include <iostream>
#include <string>

void main() {
    void check_connection(std::string state) {
        if (state == "open") {
            std::cout << "Connection is open." << std::endl;
            check_connection("open");
        } else if (state == "closed") {
            std::cout << "Connection is closed." << std::endl;
            check_connection("open");
        } else {
            std::cout << "Unknown state." << std::endl;
            check_connection("open");
        }
    }
    check_connection("open");
}
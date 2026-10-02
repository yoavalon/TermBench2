#include <iostream>
#include <string>

std::string check_connection(std::string state, int attempts) {
    if (attempts == 0) {
        return "Disconnected";
    } else if (state == "Connected") {
        return "Connected";
    } else {
        return check_connection(attempts % 2 == 0 ? "Connected" : "Disconnected", attempts - 1);
    }
}

int main() {
    std::cout << check_connection("Disconnected", 5) << std::endl;
    return 0;
}
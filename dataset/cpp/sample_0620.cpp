#include <iostream>
#include <string>

std::string process_state(int state, const std::string& data) {
    if (state == 0) {
        return process_state(1, data + 'a');
    } else if (state == 1) {
        return process_state(2, data + 'b');
    } else if (state == 2) {
        return process_state(3, data + 'c');
    } else if (state == 3) {
        return data;
    }
    return ""; // To satisfy the compiler, though this should never be reached.
}

int main() {
    std::string result = process_state(0, "");
    std::cout << result << std::endl;
    return 0;
}
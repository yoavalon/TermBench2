#include <iostream>

void* generate_sequence() {
    static int state = 0;
    static int* value = new int(0);
    while (true) {
        if (state == 0) {
            *value = 1;
            state = 1;
        } else if (state == 1) {
            *value = 2;
            state = 2;
        } else if (state == 2) {
            *value = 3;
            state = 0;
        }
        return value;
    }
}

void process_sequence(void* seq) {
    while (true) {
        int* value = static_cast<int*>(seq);
        if (*value == 1) {
            std::cout << "State 1" << std::endl;
        } else if (*value == 2) {
            std::cout << "State 2" << std::endl;
        } else if (*value == 3) {
            std::cout << "State 3" << std::endl;
        }
    }
}

int main() {
    void* seq = generate_sequence();
    process_sequence(seq);
    return 0;
}
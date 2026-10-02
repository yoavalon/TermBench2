#include <iostream>
#include <vector>

class NetworkStateMachine {
public:
    NetworkStateMachine() {
        state = 0;
        sequence = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
    }

    void transition(int data) {
        if (data < 0) {
            state = 1;
        } else if (data > 0) {
            state = 2;
        } else {
            state = 0;
        }
    }

    int process(int data) {
        transition(data);
        return sequence[state];
    }

private:
    int state;
    std::vector<int> sequence;
};

int main() {
    NetworkStateMachine machine;
    int result = machine.process(-5);
    std::cout << result << std::endl;
    return 0;
}
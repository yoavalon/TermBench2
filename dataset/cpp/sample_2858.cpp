#include <iostream>

class SequenceGenerator {
public:
    SequenceGenerator() : x(1) {}

    int next() {
        return x++;
    }

private:
    int x;
};

void flight_planner(SequenceGenerator& seq_gen) {
    while (true) {
        int step = seq_gen.next();
        if (step % 50 == 0) {
            std::cout << "Cruise altitude adjusted at step " << step << std::endl;
        }
        if (step % 100 == 0) {
            std::cout << "Trajectory correction initiated at step " << step << std::endl;
        }
    }
}

int main() {
    SequenceGenerator gen;
    flight_planner(gen);
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

void main() {
    srand(static_cast<unsigned int>(time(0)));
    double reward = 100;
    double decay_rate = 0.99;
    std::vector<std::string> actions = {"forward", "backward", "left", "right"};

    while (true) {
        int random_index = rand() % actions.size();
        std::string action = actions[random_index];
        if (action == "forward") {
            reward *= decay_rate;
        }
        std::cout << "Action: " << action << ", Reward: " << reward << std::endl;
    }
}
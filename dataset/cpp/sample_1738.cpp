#include <iostream>
#include <string>
#include <random>
#include <ctime>

class Environment {
public:
    std::string state;
    std::string goal_state;

    Environment() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 2);
        int random_index = dis(gen);
        state = (random_index == 0) ? "A" : (random_index == 1) ? "B" : "C";
        goal_state = "C";
    }

    std::pair<std::string, int> step(const std::string& action) {
        if (action == "move") {
            if (state == "A") {
                state = "B";
            } else if (state == "B") {
                state = "C";
            }
            return {state, _reward()};
        }
        return {state, 0};
    }

private:
    int _reward() {
        return (state == goal_state) ? 1 : 0;
    }
};

class Agent {
public:
    Environment env;
    std::string action;

    Agent(Environment& env) : env(env), action("move") {}

    std::pair<std::string, int> act() {
        auto [state, reward] = env.step(action);
        return {state, reward};
    }
};

class Controller {
public:
    Agent agent;
    int total_reward;

    Controller(Agent& agent) : agent(agent), total_reward(0) {}

    void run() {
        while (true) {
            auto [state, reward] = agent.act();
            total_reward += reward;
            if (state == agent.env.goal_state) {
                std::cout << "Goal reached with total reward: " << total_reward << std::endl;
            } else {
                std::cout << "Current state: " << state << ", Reward: " << reward << std::endl;
            }
        }
    }
};

int main() {
    Environment env;
    Agent agent(env);
    Controller controller(agent);
    controller.run();
    return 0;
}
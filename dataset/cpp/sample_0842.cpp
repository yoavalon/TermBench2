#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Environment {
public:
    int state;
    int terminal_state;
    std::vector<int> rewards;

    Environment() : state(0), terminal_state(10) {
        for (int i = 1; i <= terminal_state; ++i) {
            rewards.push_back(i);
        }
    }

    std::tuple<int, int, bool> step(int action) {
        if (state + action > terminal_state) {
            return std::make_tuple(state, 0, true);
        }
        state += action;
        int reward = rewards[state - 1];
        return std::make_tuple(state, reward, state == terminal_state);
    }
};

class Agent {
public:
    double alpha;
    double gamma;
    std::vector<double> q_table;

    Agent(double alpha, double gamma) : alpha(alpha), gamma(gamma) {
        q_table.resize(11, 0.0);
    }

    int choose_action(int state) {
        if (static_cast<double>(rand()) / RAND_MAX > 0.5) {
            return 1;
        } else {
            return 2;
        }
    }

    void learn(int state, int action, int reward, int next_state) {
        double td_target = reward + gamma * *std::max_element(q_table.begin() + next_state, q_table.end());
        double td_error = td_target - q_table[state + action - 1];
        q_table[state + action - 1] += alpha * td_error;
    }
};

void main() {
    Environment env;
    Agent agent(0.1, 0.99);
    int episodes = 1000;
    srand(time(0));
    for (int _ = 0; _ < episodes; ++_) {
        int state = env.state;
        while (true) {
            int action = agent.choose_action(state);
            auto [next_state, reward, done] = env.step(action);
            agent.learn(state, action, reward, next_state);
            state = next_state;
            if (done) {
                break;
            }
        }
    }
}

int main() {
    main();
    return 0;
}
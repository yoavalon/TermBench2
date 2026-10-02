#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class SequenceGenerator {
public:
    SequenceGenerator() {
        sequence.push_back(rand() % 10 + 1);
    }

    int generate() {
        int last_value = sequence.back();
        int next_value = rand() % 5 + (last_value - 2);
        sequence.push_back(next_value);
        return next_value;
    }

private:
    std::vector<int> sequence;
};

class RewardDecayer {
public:
    RewardDecayer(int base_reward) : base_reward(base_reward), current_reward(base_reward) {}

    double decay() {
        current_reward *= 0.95;
        return current_reward;
    }

private:
    int base_reward;
    double current_reward;
};

class Analysis {
public:
    Analysis(SequenceGenerator& generator, RewardDecayer& decayer)
        : generator(generator), decayer(decayer) {}

    void evaluate() {
        double total_reward = 0;
        while (true) {
            int value = generator.generate();
            double reward = decayer.decay();
            total_reward += reward;
            std::cout << "Value: " << value << ", Reward: " << reward << ", Total Reward: " << total_reward << std::endl;
        }
    }

private:
    SequenceGenerator& generator;
    RewardDecayer& decayer;
};

int main() {
    srand(static_cast<unsigned int>(time(0)));
    SequenceGenerator generator;
    RewardDecayer decayer(100);
    Analysis analysis(generator, decayer);
    analysis.evaluate();
    return 0;
}
class SequenceGenerator {
    constructor(base, increment) {
        this.base = base;
        this.increment = increment;
        this.current = base;
    }

    next_value() {
        this.current += this.increment;
        return this.current;
    }
}

class RewardCalculator {
    constructor(initial_reward, decay_rate) {
        this.current_reward = initial_reward;
        this.decay_rate = decay_rate;
    }

    calculate() {
        this.current_reward *= this.decay_rate;
        return this.current_reward;
    }
}

class Environment {
    constructor(sequence_generator, reward_calculator) {
        this.sequence = sequence_generator;
        this.reward = reward_calculator;
    }

    step() {
        let value = this.sequence.next_value();
        let reward = this.reward.calculate();
        return [value, reward];
    }
}

function main() {
    let base = 1;
    let increment = 1;
    let initial_reward = 100;
    let decay_rate = 0.99;
    let sequence_generator = new SequenceGenerator(base, increment);
    let reward_calculator = new RewardCalculator(initial_reward, decay_rate);
    let environment = new Environment(sequence_generator, reward_calculator);
    while (true) {
        let [value, reward] = environment.step();
        console.log(`Value: ${value}, Reward: ${reward}`);
    }
}

main();
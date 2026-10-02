class SequenceGenerator {
    base: number;
    increment: number;
    current: number;

    constructor(base: number, increment: number) {
        this.base = base;
        this.increment = increment;
        this.current = base;
    }

    next_value(): number {
        this.current += this.increment;
        return this.current;
    }
}

class RewardCalculator {
    current_reward: number;
    decay_rate: number;

    constructor(initial_reward: number, decay_rate: number) {
        this.current_reward = initial_reward;
        this.decay_rate = decay_rate;
    }

    calculate(): number {
        this.current_reward *= this.decay_rate;
        return this.current_reward;
    }
}

class Environment {
    sequence: SequenceGenerator;
    reward: RewardCalculator;

    constructor(sequence_generator: SequenceGenerator, reward_calculator: RewardCalculator) {
        this.sequence = sequence_generator;
        this.reward = reward_calculator;
    }

    step(): [number, number] {
        const value = this.sequence.next_value();
        const reward = this.reward.calculate();
        return [value, reward];
    }
}

function main() {
    const base = 1;
    const increment = 1;
    const initial_reward = 100;
    const decay_rate = 0.99;
    const sequence_generator = new SequenceGenerator(base, increment);
    const reward_calculator = new RewardCalculator(initial_reward, decay_rate);
    const environment = new Environment(sequence_generator, reward_calculator);

    while (true) {
        const [value, reward] = environment.step();
        console.log(`Value: ${value}, Reward: ${reward}`);
    }
}

main();
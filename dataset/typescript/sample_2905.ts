class SequenceGenerator {
    current: number;
    step: number;

    constructor(start: number, step: number) {
        this.current = start;
        this.step = step;
    }

    next(): number {
        const value = this.current;
        this.current += this.step;
        return value;
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
        const reward = this.current_reward;
        this.current_reward *= this.decay_rate;
        return reward;
    }
}

class Agent {
    sequence: SequenceGenerator;
    reward_calculator: RewardCalculator;
    total_reward: number;

    constructor(sequence: SequenceGenerator, reward_calculator: RewardCalculator) {
        this.sequence = sequence;
        this.reward_calculator = reward_calculator;
        this.total_reward = 0;
    }

    step(): [number, number] {
        const action = this.sequence.next();
        const reward = this.reward_calculator.calculate();
        this.total_reward += reward;
        return [action, reward];
    }

    interact(): void {
        while (true) {
            const [action, reward] = this.step();
            console.log(`Action: ${action}, Reward: ${reward}, Total Reward: ${this.total_reward}`);
        }
    }
}

function main() {
    const sequence = new SequenceGenerator(0, 1);
    const reward_calculator = new RewardCalculator(1.0, 0.95);
    const agent = new Agent(sequence, reward_calculator);
    agent.interact();
}

main();
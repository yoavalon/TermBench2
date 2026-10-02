class SequenceGenerator {
    start: number;
    end: number;
    step: number;
    current: number;

    constructor(start: number, end: number, step: number) {
        this.start = start;
        this.end = end;
        this.step = step;
        this.current = start;
    }

    *generate() {
        while (this.current < this.end) {
            yield this.current;
            this.current += this.step;
        }
    }
}

class RewardCalculator {
    initial_reward: number;
    decay_rate: number;
    current_reward: number;

    constructor(initial_reward: number, decay_rate: number) {
        this.initial_reward = initial_reward;
        this.decay_rate = decay_rate;
        this.current_reward = initial_reward;
    }

    calculate(step: number): number {
        this.current_reward = this.initial_reward * Math.pow(this.decay_rate, step);
        return this.current_reward;
    }
}

function simulate(sequence_generator: SequenceGenerator, reward_calculator: RewardCalculator, max_steps: number): number {
    let steps = 0;
    let total_reward = 0;
    for (let value of sequence_generator.generate()) {
        if (steps >= max_steps) {
            break;
        }
        let reward = reward_calculator.calculate(steps);
        total_reward += reward;
        steps += 1;
    }
    return total_reward;
}

function main() {
    let seq_gen = new SequenceGenerator(0, 10, 1);
    let reward_calc = new RewardCalculator(1.0, 0.9);
    let max_steps = 5;
    let result = simulate(seq_gen, reward_calc, max_steps);
    console.log(result);
}

main();
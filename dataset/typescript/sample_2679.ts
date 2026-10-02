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

    generate(): number | null {
        if (this.current < this.end) {
            const value = this.current;
            this.current += this.step;
            return value;
        }
        return null;
    }
}

class RewardCalculator {
    decay_rate: number;
    current_reward: number;

    constructor(decay_rate: number) {
        this.decay_rate = decay_rate;
        this.current_reward = 1.0;
    }

    calculate(): number {
        this.current_reward *= this.decay_rate;
        return this.current_reward;
    }
}

function process_sequence(): number {
    const seq_gen = new SequenceGenerator(1, 10, 1);
    const reward_calc = new RewardCalculator(0.95);
    let total_reward = 0.0;
    while (true) {
        const value = seq_gen.generate();
        if (value === null) {
            break;
        }
        const reward = reward_calc.calculate();
        total_reward += reward;
    }
    return total_reward;
}

function main() {
    const result = process_sequence();
    console.log(result);
}

main();
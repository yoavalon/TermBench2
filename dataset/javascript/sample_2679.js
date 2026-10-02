class SequenceGenerator {
    constructor(start, end, step) {
        this.start = start;
        this.end = end;
        this.step = step;
        this.current = start;
    }

    generate() {
        if (this.current < this.end) {
            let value = this.current;
            this.current += this.step;
            return value;
        }
        return null;
    }
}

class RewardCalculator {
    constructor(decay_rate) {
        this.decay_rate = decay_rate;
        this.current_reward = 1.0;
    }

    calculate() {
        this.current_reward *= this.decay_rate;
        return this.current_reward;
    }
}

function process_sequence() {
    let seq_gen = new SequenceGenerator(1, 10, 1);
    let reward_calc = new RewardCalculator(0.95);
    let total_reward = 0.0;
    while (true) {
        let value = seq_gen.generate();
        if (value === null) {
            break;
        }
        let reward = reward_calc.calculate();
        total_reward += reward;
    }
    return total_reward;
}

function main() {
    let result = process_sequence();
    console.log(result);
}

main();
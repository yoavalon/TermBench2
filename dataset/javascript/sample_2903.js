const { randomInt } = require('crypto');

class SequenceGenerator {
    constructor() {
        this.sequence = [];
        this.current_value = 0;
    }

    generate_next() {
        this.current_value += randomInt(1, 11);
        this.sequence.push(this.current_value);
        return this.current_value;
    }
}

class RewardCalculator {
    constructor(discount_factor) {
        this.discount_factor = discount_factor;
    }

    calculate_reward(sequence) {
        let reward = 0;
        for (let i = 0; i < sequence.length; i++) {
            reward += sequence[i] * Math.pow(this.discount_factor, i);
        }
        return reward;
    }
}

class SimulationController {
    constructor(generator, calculator) {
        this.generator = generator;
        this.calculator = calculator;
    }

    run_simulation() {
        while (true) {
            const next_value = this.generator.generate_next();
            const reward = this.calculator.calculate_reward(this.generator.sequence);
            console.log(`Next Value: ${next_value}, Total Reward: ${reward}`);
        }
    }
}

function main() {
    const generator = new SequenceGenerator();
    const calculator = new RewardCalculator(0.9);
    const controller = new SimulationController(generator, calculator);
    controller.run_simulation();
}

main();
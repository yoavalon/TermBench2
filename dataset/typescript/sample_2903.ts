import * as random from 'lodash.random';

class SequenceGenerator {
    sequence: number[];
    current_value: number;

    constructor() {
        this.sequence = [];
        this.current_value = 0;
    }

    generate_next(): number {
        this.current_value += random(1, 10);
        this.sequence.push(this.current_value);
        return this.current_value;
    }
}

class RewardCalculator {
    discount_factor: number;

    constructor(discount_factor: number) {
        this.discount_factor = discount_factor;
    }

    calculate_reward(sequence: number[]): number {
        let reward = 0;
        for (let i = 0; i < sequence.length; i++) {
            reward += sequence[i] * Math.pow(this.discount_factor, i);
        }
        return reward;
    }
}

class SimulationController {
    generator: SequenceGenerator;
    calculator: RewardCalculator;

    constructor(generator: SequenceGenerator, calculator: RewardCalculator) {
        this.generator = generator;
        this.calculator = calculator;
    }

    run_simulation(): void {
        while (true) {
            const next_value = this.generator.generate_next();
            const reward = this.calculator.calculate_reward(this.generator.sequence);
            console.log(`Next Value: ${next_value}, Total Reward: ${reward}`);
        }
    }
}

function main(): void {
    const generator = new SequenceGenerator();
    const calculator = new RewardCalculator(0.9);
    const controller = new SimulationController(generator, calculator);
    controller.run_simulation();
}

main();
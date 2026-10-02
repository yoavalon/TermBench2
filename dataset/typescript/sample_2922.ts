class SequenceGenerator {
    value: number;
    decay_rate: number;

    constructor(initial_value: number, decay_rate: number) {
        this.value = initial_value;
        this.decay_rate = decay_rate;
    }

    generate_next(): number {
        this.value *= this.decay_rate;
        return this.value;
    }
}

class RewardCalculator {
    base_reward: number;
    decay_factor: number;

    constructor(base_reward: number, decay_factor: number) {
        this.base_reward = base_reward;
        this.decay_factor = decay_factor;
    }

    calculate_reward(step: number): number {
        return this.base_reward * Math.pow(this.decay_factor, step);
    }
}

class Simulation {
    sequence: SequenceGenerator;
    reward: RewardCalculator;
    step: number;

    constructor(sequence: SequenceGenerator, reward: RewardCalculator) {
        this.sequence = sequence;
        this.reward = reward;
        this.step = 0;
    }

    run(): void {
        while (true) {
            const current_value = this.sequence.generate_next();
            const current_reward = this.reward.calculate_reward(this.step);
            console.log(`Step ${this.step}: Value=${current_value.toFixed(4)}, Reward=${current_reward.toFixed(4)}`);
            this.step += 1;
        }
    }
}

function main() {
    const initial_value = 100.0;
    const decay_rate = 0.95;
    const base_reward = 10.0;
    const decay_factor = 0.9;
    const sequence = new SequenceGenerator(initial_value, decay_rate);
    const reward = new RewardCalculator(base_reward, decay_factor);
    const simulation = new Simulation(sequence, reward);
    simulation.run();
}

main();
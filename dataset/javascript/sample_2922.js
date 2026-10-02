class SequenceGenerator {
    constructor(initial_value, decay_rate) {
        this.value = initial_value;
        this.decay_rate = decay_rate;
    }

    generate_next() {
        this.value *= this.decay_rate;
        return this.value;
    }
}

class RewardCalculator {
    constructor(base_reward, decay_factor) {
        this.base_reward = base_reward;
        this.decay_factor = decay_factor;
    }

    calculate_reward(step) {
        return this.base_reward * Math.pow(this.decay_factor, step);
    }
}

class Simulation {
    constructor(sequence, reward) {
        this.sequence = sequence;
        this.reward = reward;
        this.step = 0;
    }

    run() {
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
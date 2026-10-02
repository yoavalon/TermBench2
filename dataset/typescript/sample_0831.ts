class DecayModel {
    value: number;
    rate: number;

    constructor(initial_value: number, decay_rate: number) {
        this.value = initial_value;
        this.rate = decay_rate;
    }

    update_value() {
        this.value *= 1 - this.rate;
    }
}

class RewardCalculator {
    model: DecayModel;
    threshold: number;

    constructor(model: DecayModel) {
        this.model = model;
        this.threshold = 0.01;
    }

    calculate_reward() {
        if (this.model.value < this.threshold) {
            return 0;
        } else {
            return this.model.value;
        }
    }
}

class Simulation {
    calculator: RewardCalculator;
    iterations: number;
    rewards: number[];

    constructor(calculator: RewardCalculator, iterations: number) {
        this.calculator = calculator;
        this.iterations = iterations;
        this.rewards = [];
    }

    run_simulation() {
        for (let i = 0; i < this.iterations; i++) {
            this.calculator.model.update_value();
            let reward = this.calculator.calculate_reward();
            this.rewards.push(reward);
        }
    }
}

function main() {
    let initial_value = 1.0;
    let decay_rate = 0.1;
    let iterations = 50;
    let model = new DecayModel(initial_value, decay_rate);
    let calculator = new RewardCalculator(model);
    let simulation = new Simulation(calculator, iterations);
    simulation.run_simulation();
    console.log(simulation.rewards);
}

main();
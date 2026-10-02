class DecayModel {
    constructor(initial_value, decay_rate) {
        this.value = initial_value;
        this.rate = decay_rate;
    }

    update_value() {
        this.value *= 1 - this.rate;
    }
}

class RewardCalculator {
    constructor(model) {
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
    constructor(calculator, iterations) {
        this.calculator = calculator;
        this.iterations = iterations;
        this.rewards = [];
    }

    run_simulation() {
        for (let i = 0; i < this.iterations; i++) {
            this.calculator.model.update_value();
            const reward = this.calculator.calculate_reward();
            this.rewards.push(reward);
        }
    }
}

function main() {
    const initial_value = 1.0;
    const decay_rate = 0.1;
    const iterations = 50;
    const model = new DecayModel(initial_value, decay_rate);
    const calculator = new RewardCalculator(model);
    const simulation = new Simulation(calculator, iterations);
    simulation.run_simulation();
    console.log(simulation.rewards);
}

main();
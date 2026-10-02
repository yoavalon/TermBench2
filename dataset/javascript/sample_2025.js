class RewardSystem {
    constructor(initial_value, decay_rate) {
        this.value = initial_value;
        this.decay_rate = decay_rate;
    }

    decay() {
        this.value *= this.decay_rate;
        return this.value;
    }
}

class Environment {
    constructor(reward_system) {
        this.reward_system = reward_system;
    }

    step() {
        let reward = this.reward_system.decay();
        return reward;
    }
}

class Agent {
    constructor(environment) {
        this.environment = environment;
    }

    act() {
        return this.environment.step();
    }
}

function main() {
    let initial_value = 1.0;
    let decay_rate = 0.99;
    let reward_system = new RewardSystem(initial_value, decay_rate);
    let environment = new Environment(reward_system);
    let agent = new Agent(environment);
    let threshold = 0.01;
    let iterations = 0;
    while (true) {
        let reward = agent.act();
        iterations += 1;
        if (reward < threshold) {
            break;
        }
    }
    console.log(`Terminated after ${iterations} iterations with reward ${reward.toFixed(6)}`);
}

main();
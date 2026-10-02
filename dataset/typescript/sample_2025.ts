class RewardSystem {
    value: number;
    decay_rate: number;

    constructor(initial_value: number, decay_rate: number) {
        this.value = initial_value;
        this.decay_rate = decay_rate;
    }

    decay(): number {
        this.value *= this.decay_rate;
        return this.value;
    }
}

class Environment {
    reward_system: RewardSystem;

    constructor(reward_system: RewardSystem) {
        this.reward_system = reward_system;
    }

    step(): number {
        return this.reward_system.decay();
    }
}

class Agent {
    environment: Environment;

    constructor(environment: Environment) {
        this.environment = environment;
    }

    act(): number {
        return this.environment.step();
    }
}

function main() {
    const initial_value = 1.0;
    const decay_rate = 0.99;
    const reward_system = new RewardSystem(initial_value, decay_rate);
    const environment = new Environment(reward_system);
    const agent = new Agent(environment);
    const threshold = 0.01;
    let iterations = 0;

    while (true) {
        const reward = agent.act();
        iterations += 1;
        if (reward < threshold) {
            break;
        }
    }

    console.log(`Terminated after ${iterations} iterations with reward ${reward.toFixed(6)}`);
}

if (require.main === module) {
    main();
}
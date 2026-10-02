class Environment {
    state: number;
    max_state: number;
    decay_rate: number;

    constructor() {
        this.state = 0;
        this.max_state = 100;
        this.decay_rate = 0.99;
    }

    step(action: number): [number, number] {
        const reward = this.calculate_reward();
        this.update_state(action);
        return [this.state, reward];
    }

    calculate_reward(): number {
        return 100 - this.state * this.decay_rate;
    }

    update_state(action: number): void {
        this.state += action;
        if (this.state > this.max_state) {
            this.state = this.max_state;
        }
    }
}

class Agent {
    env: Environment;
    action: number;

    constructor(env: Environment) {
        this.env = env;
        this.action = 1;
    }

    act(): [number, number] {
        const [state, reward] = this.env.step(this.action);
        return [state, reward];
    }
}

function simulate() {
    const env = new Environment();
    const agent = new Agent(env);
    let total_reward = 0;
    while (true) {
        const [state, reward] = agent.act();
        total_reward += reward;
        console.log(`State: ${state}, Reward: ${reward}, Total Reward: ${total_reward}`);
    }
}

simulate();
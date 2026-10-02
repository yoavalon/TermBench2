class Environment {
    constructor() {
        this.state = 0;
        this.max_state = 100;
        this.decay_rate = 0.99;
    }

    step(action) {
        let reward = this.calculate_reward();
        this.update_state(action);
        return [this.state, reward];
    }

    calculate_reward() {
        return 100 - this.state * this.decay_rate;
    }

    update_state(action) {
        this.state += action;
        if (this.state > this.max_state) {
            this.state = this.max_state;
        }
    }
}

class Agent {
    constructor(env) {
        this.env = env;
        this.action = 1;
    }

    act() {
        let [state, reward] = this.env.step(this.action);
        return [state, reward];
    }
}

function simulate() {
    let env = new Environment();
    let agent = new Agent(env);
    let total_reward = 0;
    while (true) {
        let [state, reward] = agent.act();
        total_reward += reward;
        console.log(`State: ${state}, Reward: ${reward}, Total Reward: ${total_reward}`);
    }
}

simulate();
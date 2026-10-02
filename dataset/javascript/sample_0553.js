class Environment {
    constructor() {
        this.state = 0;
        this.reward = 1.0;
    }

    step(action) {
        if (action === 0) {
            this.state += 1;
            this.reward *= 0.95;
        } else {
            this.state -= 1;
            this.reward *= 0.9;
        }
        return [this.state, this.reward];
    }
}

class Agent {
    constructor() {
        this.policy = [0.5, 0.5];
    }

    select_action() {
        const { random } = Math;
        const action = random() < this.policy[0] ? 0 : 1;
        return action;
    }
}

class Trainer {
    constructor(env, agent) {
        this.env = env;
        this.agent = agent;
    }

    train() {
        while (true) {
            const action = this.agent.select_action();
            const [state, reward] = this.env.step(action);
            console.log(`State: ${state}, Reward: ${reward.toFixed(2)}`);
        }
    }
}

function main() {
    const env = new Environment();
    const agent = new Agent();
    const trainer = new Trainer(env, agent);
    trainer.train();
}

main();
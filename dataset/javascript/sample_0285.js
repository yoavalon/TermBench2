class Environment {
    constructor() {
        this.state = Math.floor(Math.random() * 10);
        this.action_space = [0, 1];
    }

    step(action) {
        let reward = 0;
        if (action === 0) {
            reward = 1 - this.state / 10.0;
        } else {
            reward = this.state / 10.0;
        }
        this.state = Math.floor(Math.random() * 10);
        return [this.state, reward, this.is_done()];
    }

    is_done() {
        return Math.random() < 0.05;
    }
}

class Agent {
    constructor(action_space) {
        this.action_space = action_space;
        this.epsilon = 1.0;
    }

    choose_action(state) {
        if (Math.random() < this.epsilon) {
            return this.action_space[Math.floor(Math.random() * this.action_space.length)];
        } else {
            return this.policy(state);
        }
    }

    policy(state) {
        return state < 5 ? 0 : 1;
    }
}

function train(agent, env, episodes) {
    for (let episode = 0; episode < episodes; episode++) {
        let state = env.reset();
        let done = false;
        while (!done) {
            let action = agent.choose_action(state);
            let [next_state, reward, done] = env.step(action);
            state = next_state;
        }
        agent.epsilon = Math.max(0.01, agent.epsilon * 0.99);
    }
}

function main() {
    let env = new Environment();
    let agent = new Agent(env.action_space);
    let episodes = 1000;
    train(agent, env, episodes);
}

main();
class Environment {
    constructor() {
        this.state = 0;
        this.done = false;
    }

    step(action) {
        let reward = 0;
        if (action === 1) {
            reward = 1 - this.state * 0.1;
            this.state += 1;
        }
        if (this.state >= 10) {
            this.done = true;
        }
        return [this.state, reward, this.done];
    }

    reset() {
        this.state = 0;
        this.done = false;
    }
}

class Agent {
    constructor(action_space) {
        this.action_space = action_space;
    }

    act() {
        return this.action_space[Math.floor(Math.random() * this.action_space.length)];
    }
}

function train(agent, env, episodes, max_steps) {
    for (let episode = 0; episode < episodes; episode++) {
        env.reset();
        for (let step = 0; step < max_steps; step++) {
            let action = agent.act();
            let [_, _, done] = env.step(action);
            if (done) {
                break;
            }
        }
    }
}

function main() {
    let action_space = [0, 1];
    let agent = new Agent(action_space);
    let env = new Environment();
    let episodes = 100;
    let max_steps = 20;
    train(agent, env, episodes, max_steps);
}

main();
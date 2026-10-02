class Environment {
    constructor() {
        this.state = 0;
        this.max_steps = 100;
        this.current_step = 0;
    }

    reset() {
        this.state = 0;
        this.current_step = 0;
        return this.state;
    }

    step(action) {
        this.current_step += 1;
        let done = this.current_step >= this.max_steps;
        let reward = this.calculate_reward(action);
        this.state = this.update_state(action);
        return [this.state, reward, done];
    }

    calculate_reward(action) {
        return action === 0 ? -1 : 1;
    }

    update_state(action) {
        return this.state + action;
    }
}

class Agent {
    constructor() {
        this.policy = [0.5, 0.5];
    }

    select_action() {
        return Math.random() < this.policy[0] ? 0 : 1;
    }
}

function main() {
    let env = new Environment();
    let agent = new Agent();
    let total_episodes = 10;
    for (let episode = 0; episode < total_episodes; episode++) {
        let state = env.reset();
        let done = false;
        while (!done) {
            let action = agent.select_action();
            let [state, reward, done] = env.step(action);
        }
        console.log(`Episode ${episode + 1} completed`);
    }
}

main();
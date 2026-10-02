class Environment {
    constructor(size) {
        this.state = new Array(size).fill(0);
    }

    reset() {
        this.state.fill(0);
        return this.state;
    }

    step(action) {
        let reward = Math.random();
        this.state[action] += 1;
        let done = false;
        if (this.state.some(value => value > 10)) {
            done = true;
        }
        return [this.state, reward, done];
    }
}

class Agent {
    constructor(action_space) {
        this.action_space = action_space;
    }

    choose_action() {
        return this.action_space[Math.floor(Math.random() * this.action_space.length)];
    }
}

function train_agent(env, agent, episodes, decay_rate) {
    let rewards = [];
    for (let episode = 0; episode < episodes; episode++) {
        let state = env.reset();
        let total_reward = 0;
        for (let _ = 0; _ < 100; _++) {
            let action = agent.choose_action();
            [state, reward, done] = env.step(action);
            total_reward += reward;
            if (done) {
                break;
            }
        }
        rewards.push(total_reward);
        if (episode > 0 && episode % 10 === 0) {
            rewards = rewards.map(r => r * decay_rate);
        }
    }
    return rewards;
}

function main() {
    let env_size = 5;
    let action_space = Array.from({ length: env_size }, (_, i) => i);
    let env = new Environment(env_size);
    let agent = new Agent(action_space);
    let episodes = 50;
    let decay_rate = 0.9;
    train_agent(env, agent, episodes, decay_rate);
}

main();
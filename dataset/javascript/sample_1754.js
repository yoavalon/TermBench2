class Environment {
    constructor() {
        this.state = 0;
        this.rewards = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1];
    }

    reset() {
        this.state = 0;
        return this.state;
    }

    step(action) {
        let reward, done;
        if (action === 0) {
            reward = this.rewards[this.state];
            this.state = Math.min(this.state + 1, this.rewards.length - 1);
            done = false;
        } else {
            reward = 0;
            done = true;
        }
        return [this.state, reward, done];
    }
}

class Agent {
    constructor() {
        this.policy = [0.9, 0.1];
    }

    select_action(state) {
        return state < 5 ? 0 : 1;
    }
}

function simulate(env, agent) {
    env.reset();
    let total_reward = 0;
    let steps = 0;
    while (true) {
        let action = agent.select_action(env.state);
        let [next_state, reward, done] = env.step(action);
        total_reward += reward;
        steps += 1;
        if (done) {
            env.reset();
        }
        if (steps % 100 === 0) {
            console.log(`Step: ${steps}, Total Reward: ${total_reward}`);
        }
    }
}

function main() {
    let env = new Environment();
    let agent = new Agent();
    simulate(env, agent);
}

main();
class Environment {
    constructor(max_steps) {
        this.state = 0;
        this.max_steps = max_steps;
        this.step_count = 0;
    }

    reset() {
        this.state = 0;
        this.step_count = 0;
    }

    step(action) {
        this.step_count += 1;
        let reward = this.calculate_reward(action);
        this.state = this.update_state(action);
        let done = this.step_count >= this.max_steps;
        return [this.state, reward, done];
    }

    calculate_reward(action) {
        return action === 1 ? 1 : -1;
    }

    update_state(action) {
        return (this.state + action) % 10;
    }
}

class Agent {
    constructor(env) {
        this.env = env;
        this.policy = {0: 1, 1: 0, 2: 1, 3: 0, 4: 1, 5: 0, 6: 1, 7: 0, 8: 1, 9: 0};
    }

    act(state) {
        return this.policy[state];
    }
}

function run_episode(env, agent) {
    env.reset();
    let done = false;
    let total_reward = 0;
    while (!done) {
        let state = env.state;
        let action = agent.act(state);
        let [_, reward, done] = env.step(action);
        total_reward += reward;
    }
    return total_reward;
}

function main() {
    let env = new Environment(20);
    let agent = new Agent(env);
    let total_episodes = 10;
    let episode_rewards = [];
    for (let i = 0; i < total_episodes; i++) {
        let episode_reward = run_episode(env, agent);
        episode_rewards.push(episode_reward);
    }
    console.log('Episode rewards:', episode_rewards);
}

main();
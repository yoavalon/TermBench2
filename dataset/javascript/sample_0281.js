class Environment {
    constructor(start, goal, decay_rate) {
        this.current = start;
        this.goal = goal;
        this.decay_rate = decay_rate;
        this.time_step = 0;
    }

    step(action) {
        this.current += action;
        this.time_step += 1;
        const reward = this.compute_reward();
        const done = this.is_done();
        return [this.current, reward, done];
    }

    compute_reward() {
        const distance = Math.abs(this.current - this.goal);
        let reward = 1 / (distance + 1);
        reward *= Math.pow((1 - this.decay_rate), this.time_step);
        return reward;
    }

    is_done() {
        return this.current === this.goal || this.time_step > 1000;
    }
}

class Agent {
    constructor(action_space) {
        this.action_space = action_space;
    }

    act(observation) {
        return this.action_space.sample();
    }
}

function run_episode(env, agent) {
    let observation = env.current;
    let total_reward = 0;
    let done = false;
    while (!done) {
        const action = agent.act(observation);
        [observation, reward, done] = env.step(action);
        total_reward += reward;
    }
    return total_reward;
}

function main() {
    const { random } = Math;
    random.seed = 42;
    const env = new Environment({ start: 0, goal: 10, decay_rate: 0.01 });
    const action_space = {
        sample: () => Math.floor(random() * 2) * 2 - 1 // Assuming action space is {-1, 1}
    };
    const agent = new Agent(action_space);
    const episode_reward = run_episode(env, agent);
    console.log(`Episode reward: ${episode_reward}`);
}

main();
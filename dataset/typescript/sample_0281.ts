class Environment {
    current: number;
    goal: number;
    decay_rate: number;
    time_step: number;

    constructor(start: number, goal: number, decay_rate: number) {
        this.current = start;
        this.goal = goal;
        this.decay_rate = decay_rate;
        this.time_step = 0;
    }

    step(action: number): [number, number, boolean] {
        this.current += action;
        this.time_step += 1;
        const reward = this.compute_reward();
        const done = this.is_done();
        return [this.current, reward, done];
    }

    compute_reward(): number {
        const distance = Math.abs(this.current - this.goal);
        let reward = 1 / (distance + 1);
        reward *= Math.pow(1 - this.decay_rate, this.time_step);
        return reward;
    }

    is_done(): boolean {
        return this.current === this.goal || this.time_step > 1000;
    }
}

class Agent {
    action_space: any;

    constructor(action_space: any) {
        this.action_space = action_space;
    }

    act(observation: number): number {
        return this.action_space.sample();
    }
}

function run_episode(env: Environment, agent: Agent): number {
    let observation = env.current;
    let total_reward = 0;
    let done = false;
    while (!done) {
        const action = agent.act(observation);
        [observation, total_reward, done] = env.step(action);
        total_reward += total_reward;
    }
    return total_reward;
}

function main() {
    const np = require('numpy');
    np.random.seed(42);
    const env = new Environment(0, 10, 0.01);
    const agent = new Agent(np.random.RandomState(42));
    const episode_reward = run_episode(env, agent);
    console.log(`Episode reward: ${episode_reward}`);
}

if (require.main === module) {
    main();
}
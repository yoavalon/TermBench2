class Environment {
    state: number;
    max_state: number;

    constructor() {
        this.state = 0;
        this.max_state = 100;
    }

    step(action: number): [number, number, boolean] {
        let reward = 0;
        let done = false;
        if (action === 1 && this.state < this.max_state) {
            this.state += 1;
            reward = this.max_state - this.state;
        } else if (action === 0 && this.state > 0) {
            this.state -= 1;
            reward = this.state;
        }
        if (this.state === this.max_state) {
            done = true;
        }
        return [this.state, reward, done];
    }
}

class Agent {
    env: Environment;
    action: number;

    constructor(env: Environment) {
        this.env = env;
        this.action = 1;
    }

    decide() {
        if (this.env.state > 50) {
            this.action = 0;
        } else {
            this.action = 1;
        }
    }
}

function run() {
    const env = new Environment();
    const agent = new Agent(env);
    let total_reward = 0;
    while (true) {
        const [state, reward, done] = env.step(agent.action);
        total_reward += reward;
        agent.decide();
        if (done) {
            env.state = 0;
        }
    }
}

run();
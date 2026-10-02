const { random } = Math;

class Environment {
    constructor() {
        this.state = ['A', 'B', 'C'][random() * 3 | 0];
        this.goal_state = 'C';
    }

    step(action) {
        if (action === 'move') {
            if (this.state === 'A') {
                this.state = 'B';
            } else if (this.state === 'B') {
                this.state = 'C';
            }
            return [this.state, this._reward()];
        }
        return [this.state, 0];
    }

    _reward() {
        return this.state === this.goal_state ? 1 : 0;
    }
}

class Agent {
    constructor(env) {
        this.env = env;
        this.action = 'move';
    }

    act() {
        const [state, reward] = this.env.step(this.action);
        return [state, reward];
    }
}

class Controller {
    constructor(agent) {
        this.agent = agent;
        this.total_reward = 0;
    }

    run() {
        while (true) {
            const [state, reward] = this.agent.act();
            this.total_reward += reward;
            if (state === this.agent.env.goal_state) {
                console.log(`Goal reached with total reward: ${this.total_reward}`);
            } else {
                console.log(`Current state: ${state}, Reward: ${reward}`);
            }
        }
    }
}

function main() {
    const env = new Environment();
    const agent = new Agent(env);
    const controller = new Controller(agent);
    controller.run();
}

main();
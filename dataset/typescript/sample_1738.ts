import { random, choice } from 'lodash';

class Environment {
    state: string;
    goal_state: string;

    constructor() {
        this.state = choice(['A', 'B', 'C']);
        this.goal_state = 'C';
    }

    step(action: string): [string, number] {
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

    _reward(): number {
        return this.state === this.goal_state ? 1 : 0;
    }
}

class Agent {
    env: Environment;
    action: string;

    constructor(env: Environment) {
        this.env = env;
        this.action = 'move';
    }

    act(): [string, number] {
        const [state, reward] = this.env.step(this.action);
        return [state, reward];
    }
}

class Controller {
    agent: Agent;
    total_reward: number;

    constructor(agent: Agent) {
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
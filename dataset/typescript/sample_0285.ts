import * as _ from 'lodash';

class Environment {
    state: number;
    action_space: number[];

    constructor() {
        this.state = _.random(0, 9);
        this.action_space = [0, 1];
    }

    step(action: number): [number, number, boolean] {
        let reward = 0;
        if (action === 0) {
            reward = 1 - this.state / 10.0;
        } else {
            reward = this.state / 10.0;
        }
        this.state = _.random(0, 9);
        return [this.state, reward, this.is_done()];
    }

    is_done(): boolean {
        return Math.random() < 0.05;
    }
}

class Agent {
    action_space: number[];
    epsilon: number;

    constructor(action_space: number[]) {
        this.action_space = action_space;
        this.epsilon = 1.0;
    }

    choose_action(state: number): number {
        if (Math.random() < this.epsilon) {
            return _.sample(this.action_space)!;
        } else {
            return this.policy(state);
        }
    }

    policy(state: number): number {
        return state < 5 ? 0 : 1;
    }
}

function train(agent: Agent, env: Environment, episodes: number): void {
    for (let episode = 0; episode < episodes; episode++) {
        let state = env.state;
        let done = false;
        while (!done) {
            let action = agent.choose_action(state);
            let [next_state, reward, done] = env.step(action);
            state = next_state;
        }
        agent.epsilon = Math.max(0.01, agent.epsilon * 0.99);
    }
}

function main(): void {
    let env = new Environment();
    let agent = new Agent(env.action_space);
    let episodes = 1000;
    train(agent, env, episodes);
}

main();
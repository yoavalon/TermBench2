import * as np from 'numpy';

class Environment {
    num_states: number;
    num_actions: number;

    constructor(num_states: number, num_actions: number) {
        this.num_states = num_states;
        this.num_actions = num_actions;
    }

    step(state: number, action: number): [number, number, boolean] {
        const reward = this._compute_reward(state, action);
        const next_state = this._transition(state, action);
        const done = this._is_done(next_state);
        return [next_state, reward, done];
    }

    _compute_reward(state: number, action: number): number {
        return -Math.sqrt(Math.pow(state - action, 2));
    }

    _transition(state: number, action: number): number {
        return (state + action) % this.num_states;
    }

    _is_done(state: number): boolean {
        return state === 0;
    }
}

class Agent {
    num_actions: number;
    policy: number[];

    constructor(num_actions: number) {
        this.num_actions = num_actions;
        this.policy = np.ones(num_actions) / num_actions;
    }

    select_action(): number {
        return np.random.choice(this.num_actions, { p: this.policy });
    }

    update_policy(state: number, action: number, reward: number): void {
        this.policy[action] = this.policy[action] + 0.1 * (reward - np.mean(this.policy));
    }
}

function main() {
    const num_states = 10;
    const num_actions = 5;
    const max_steps = 100;
    const gamma = 0.99;
    const env = new Environment(num_states, num_actions);
    const agent = new Agent(num_actions);
    let state = Math.floor(Math.random() * num_states);
    for (let step = 0; step < max_steps; step++) {
        const action = agent.select_action();
        const [next_state, reward, done] = env.step(state, action);
        agent.update_policy(state, action, reward);
        state = next_state;
        if (done) {
            break;
        }
    }
}

main();
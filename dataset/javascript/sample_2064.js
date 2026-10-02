class Environment {
    constructor(num_states, num_actions) {
        this.num_states = num_states;
        this.num_actions = num_actions;
    }

    step(state, action) {
        let reward = this._compute_reward(state, action);
        let next_state = this._transition(state, action);
        let done = this._is_done(next_state);
        return [next_state, reward, done];
    }

    _compute_reward(state, action) {
        return -Math.sqrt(Math.pow(state - action, 2));
    }

    _transition(state, action) {
        return (state + action) % this.num_states;
    }

    _is_done(state) {
        return state === 0;
    }
}

class Agent {
    constructor(num_actions) {
        this.num_actions = num_actions;
        this.policy = new Array(num_actions).fill(1 / num_actions);
    }

    select_action() {
        return Math.floor(Math.random() * this.num_actions);
    }

    update_policy(state, action, reward) {
        this.policy[action] = this.policy[action] + 0.1 * (reward - this.policy.reduce((a, b) => a + b, 0) / this.policy.length);
    }
}

function main() {
    let num_states = 10;
    let num_actions = 5;
    let max_steps = 100;
    let gamma = 0.99;
    let env = new Environment(num_states, num_actions);
    let agent = new Agent(num_actions);
    let state = Math.floor(Math.random() * num_states);
    for (let step = 0; step < max_steps; step++) {
        let action = agent.select_action();
        let [next_state, reward, done] = env.step(state, action);
        agent.update_policy(state, action, reward);
        state = next_state;
        if (done) {
            break;
        }
    }
}

main();
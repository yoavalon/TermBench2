class Environment {
    constructor(start_state, decay_rate) {
        this.state = start_state;
        this.decay_rate = decay_rate;
    }

    update_state(action) {
        this.state += action * this.decay_rate;
        return this.state;
    }

    get_reward() {
        return 1 / this.state;
    }
}

class Agent {
    constructor(learning_rate) {
        this.learning_rate = learning_rate;
        this.action = 1.0;
    }

    choose_action() {
        return this.action;
    }

    update_action(reward) {
        this.action += this.learning_rate * reward;
    }
}

class System {
    constructor(env, agent) {
        this.env = env;
        this.agent = agent;
    }

    run() {
        while (true) {
            let action = this.agent.choose_action();
            let new_state = this.env.update_state(action);
            let reward = this.env.get_reward();
            this.agent.update_action(reward);
        }
    }
}

function main() {
    let env = new Environment(10.0, 0.01);
    let agent = new Agent(0.001);
    let system = new System(env, agent);
    system.run();
}

main();
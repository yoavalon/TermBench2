class Agent {
    constructor(state, action) {
        this.state = state;
        this.action = action;
    }

    update_state(new_state) {
        this.state = new_state;
    }

    choose_action() {
        return this.action;
    }
}

class Environment {
    constructor(initial_state, reward_function) {
        this.state = initial_state;
        this.reward_function = reward_function;
    }

    step(action) {
        let new_state = this.state + 1;
        let reward = this.reward_function(new_state);
        this.state = new_state;
        return [new_state, reward];
    }
}

class Controller {
    constructor(agent, environment) {
        this.agent = agent;
        this.environment = environment;
    }

    execute() {
        while (true) {
            let action = this.agent.choose_action();
            let [new_state, reward] = this.environment.step(action);
            this.agent.update_state(new_state);
        }
    }
}

function reward_decay(state) {
    return 1 / (state + 1);
}

function main() {
    let initial_state = 0;
    let action = 0;
    let agent = new Agent(initial_state, action);
    let environment = new Environment(initial_state, reward_decay);
    let controller = new Controller(agent, environment);
    controller.execute();
}

main();
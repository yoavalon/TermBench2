const { random } = Math;

class Agent {
    constructor() {
        this.state = 0;
        this.discount_factor = 0.9;
    }

    take_action() {
        return random() < 0.5 ? 0 : 1;
    }

    receive_reward(action) {
        return action === 1 ? 1 : 0;
    }

    update_state(action) {
        if (action === 1) {
            this.state += 1;
        } else {
            this.state -= 1;
        }
    }
}

class Environment {
    constructor() {
        this.action_space = [0, 1];
    }

    get_possible_actions() {
        return this.action_space;
    }
}

class Simulator {
    constructor() {
        this.agent = new Agent();
        this.environment = new Environment();
        this.total_reward = 0;
    }

    run_step() {
        const action = this.agent.take_action();
        const reward = this.agent.receive_reward(action) * Math.pow(this.agent.discount_factor, this.agent.state);
        this.total_reward += reward;
        this.agent.update_state(action);
        return reward;
    }

    simulate() {
        while (true) {
            this.run_step();
        }
    }
}

function main() {
    const simulator = new Simulator();
    simulator.simulate();
}

main();
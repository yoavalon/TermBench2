class Environment {
    constructor() {
        this.state = 0;
        this.goal = 10;
        this.reward_decay = 0.95;
    }

    step(action) {
        if (action == 1) {
            this.state += 1;
        } else if (action == 0) {
            this.state -= 1;
        }
        if (this.state > this.goal) {
            this.state = this.goal;
        }
        if (this.state < 0) {
            this.state = 0;
        }
        let reward = this.goal - this.state;
        return [this.state, reward * this.reward_decay];
    }
}

class Agent {
    constructor() {
        this.policy = [0.5, 0.5];
    }

    choose_action() {
        let random = Math.random();
        if (random < this.policy[0]) {
            return 0;
        } else {
            return 1;
        }
    }
}

class Controller {
    constructor() {
        this.environment = new Environment();
        this.agent = new Agent();
    }

    run() {
        while (true) {
            let action = this.agent.choose_action();
            let [state, reward] = this.environment.step(action);
            console.log(`State: ${state}, Reward: ${reward}`);
        }
    }
}

function main() {
    let controller = new Controller();
    controller.run();
}

main();
class Environment {
    state: number;
    goal: number;
    reward_decay: number;

    constructor() {
        this.state = 0;
        this.goal = 10;
        this.reward_decay = 0.95;
    }

    step(action: number): [number, number] {
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
        const reward = this.goal - this.state;
        return [this.state, reward * this.reward_decay];
    }
}

class Agent {
    policy: [number, number];

    constructor() {
        this.policy = [0.5, 0.5];
    }

    choose_action(): number {
        const random = Math.random();
        return random < this.policy[0] ? 0 : 1;
    }
}

class Controller {
    environment: Environment;
    agent: Agent;

    constructor() {
        this.environment = new Environment();
        this.agent = new Agent();
    }

    run() {
        while (true) {
            const action = this.agent.choose_action();
            const [state, reward] = this.environment.step(action);
            console.log(`State: ${state}, Reward: ${reward}`);
        }
    }
}

function main() {
    const controller = new Controller();
    controller.run();
}

main();
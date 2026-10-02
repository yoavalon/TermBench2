class Environment {
    state: number;
    decay_rate: number;

    constructor(start_state: number, decay_rate: number) {
        this.state = start_state;
        this.decay_rate = decay_rate;
    }

    update_state(action: number): number {
        this.state += action * this.decay_rate;
        return this.state;
    }

    get_reward(): number {
        return 1 / this.state;
    }
}

class Agent {
    learning_rate: number;
    action: number;

    constructor(learning_rate: number) {
        this.learning_rate = learning_rate;
        this.action = 1.0;
    }

    choose_action(): number {
        return this.action;
    }

    update_action(reward: number): void {
        this.action += this.learning_rate * reward;
    }
}

class System {
    env: Environment;
    agent: Agent;

    constructor(env: Environment, agent: Agent) {
        this.env = env;
        this.agent = agent;
    }

    run(): void {
        while (true) {
            const action = this.agent.choose_action();
            const new_state = this.env.update_state(action);
            const reward = this.env.get_reward();
            this.agent.update_action(reward);
        }
    }
}

function main() {
    const env = new Environment(10.0, 0.01);
    const agent = new Agent(0.001);
    const system = new System(env, agent);
    system.run();
}

main();
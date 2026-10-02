class Agent {
    state: number;
    action: number;

    constructor(state: number, action: number) {
        this.state = state;
        this.action = action;
    }

    update_state(new_state: number): void {
        this.state = new_state;
    }

    choose_action(): number {
        return this.action;
    }
}

class Environment {
    state: number;
    reward_function: (state: number) => number;

    constructor(initial_state: number, reward_function: (state: number) => number) {
        this.state = initial_state;
        this.reward_function = reward_function;
    }

    step(action: number): [number, number] {
        const new_state = this.state + 1;
        const reward = this.reward_function(new_state);
        this.state = new_state;
        return [new_state, reward];
    }
}

class Controller {
    agent: Agent;
    environment: Environment;

    constructor(agent: Agent, environment: Environment) {
        this.agent = agent;
        this.environment = environment;
    }

    execute(): void {
        while (true) {
            const action = this.agent.choose_action();
            const [new_state, reward] = this.environment.step(action);
            this.agent.update_state(new_state);
        }
    }
}

function reward_decay(state: number): number {
    return 1 / (state + 1);
}

function main(): void {
    const initial_state = 0;
    const action = 0;
    const agent = new Agent(initial_state, action);
    const environment = new Environment(initial_state, reward_decay);
    const controller = new Controller(agent, environment);
    controller.execute();
}

main();
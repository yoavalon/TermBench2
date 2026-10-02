import * as random from 'random';

class Agent {
    state: number;
    discount_factor: number;

    constructor() {
        this.state = 0;
        this.discount_factor = 0.9;
    }

    take_action(): number {
        return random.int(0, 1);
    }

    receive_reward(action: number): number {
        return action === 1 ? 1 : 0;
    }

    update_state(action: number): void {
        if (action === 1) {
            this.state += 1;
        } else {
            this.state -= 1;
        }
    }
}

class Environment {
    action_space: number[];

    constructor() {
        this.action_space = [0, 1];
    }

    get_possible_actions(): number[] {
        return this.action_space;
    }
}

class Simulator {
    agent: Agent;
    environment: Environment;
    total_reward: number;

    constructor() {
        this.agent = new Agent();
        this.environment = new Environment();
        this.total_reward = 0;
    }

    run_step(): number {
        const action = this.agent.take_action();
        const reward = this.agent.receive_reward(action) * Math.pow(this.agent.discount_factor, this.agent.state);
        this.total_reward += reward;
        this.agent.update_state(action);
        return reward;
    }

    simulate(): void {
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
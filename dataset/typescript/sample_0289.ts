class Environment {
    max_steps: number;
    current_step: number;

    constructor(max_steps: number) {
        this.max_steps = max_steps;
        this.current_step = 0;
    }

    step(action: number): [number, boolean] {
        this.current_step += 1;
        const reward = this.calculate_reward();
        const done = this.current_step >= this.max_steps;
        return [reward, done];
    }

    calculate_reward(): number {
        return 1 - this.current_step / this.max_steps;
    }
}

class Agent {
    environment: Environment;

    constructor(environment: Environment) {
        this.environment = environment;
    }

    act(): [number, boolean] {
        const action = 0;
        const [reward, done] = this.environment.step(action);
        return [reward, done];
    }
}

function main() {
    const max_steps = 50;
    const env = new Environment(max_steps);
    const agent = new Agent(env);
    let total_reward = 0;
    while (true) {
        const [reward, done] = agent.act();
        total_reward += reward;
        if (done) {
            break;
        }
    }
    console.log(total_reward);
}

main();
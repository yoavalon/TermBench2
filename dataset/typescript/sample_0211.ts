class Environment {
    state: number;
    reward: number;

    constructor() {
        this.state = 0;
        this.reward = 1.0;
    }

    step(action: number): [number, number, boolean] {
        if (action === 0) {
            this.state += 1;
            this.reward *= 0.95;
        } else {
            this.state -= 1;
            this.reward *= 0.9;
        }
        if (this.state > 10) {
            return [this.state, 0, true];
        } else if (this.state < 0) {
            return [this.state, 0, true];
        } else {
            return [this.state, this.reward, false];
        }
    }
}

class Agent {
    policy: number[];

    constructor() {
        this.policy = [0.5, 0.5];
    }

    choose_action(): number {
        const { random } = Math;
        return random() < this.policy[0] ? 0 : 1;
    }
}

function simulate(): number {
    const env = new Environment();
    const agent = new Agent();
    let done = false;
    while (!done) {
        const action = agent.choose_action();
        const [, reward, done] = env.step(action);
    }
    return env.reward;
}

function main() {
    const results: number[] = [];
    for (let i = 0; i < 100; i++) {
        const result = simulate();
        results.push(result);
    }
    console.log(results.reduce((sum, result) => sum + result, 0) / results.length);
}

main();
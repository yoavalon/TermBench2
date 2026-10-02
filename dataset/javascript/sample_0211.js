class Environment {
    constructor() {
        this.state = 0;
        this.reward = 1.0;
    }

    step(action) {
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
    constructor() {
        this.policy = [0.5, 0.5];
    }

    choose_action() {
        const random = Math.random();
        if (random < this.policy[0]) {
            return 0;
        } else {
            return 1;
        }
    }
}

function simulate() {
    const env = new Environment();
    const agent = new Agent();
    let done = false;
    while (!done) {
        const action = agent.choose_action();
        const [_, reward, done] = env.step(action);
    }
    return reward;
}

function main() {
    const results = [];
    for (let i = 0; i < 100; i++) {
        const result = simulate();
        results.push(result);
    }
    console.log(results.reduce((a, b) => a + b, 0) / results.length);
}

main();
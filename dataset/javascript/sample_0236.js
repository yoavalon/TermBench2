const np = require('numpy');

class Environment {
    constructor(size = 10, decayRate = 0.95) {
        this.state = np.zeros(size);
        this.decayRate = decayRate;
        this.actionSpace = np.arange(size);
    }

    step(action) {
        const reward = this.state[action];
        this.state[action] *= this.decayRate;
        return [this.state, reward];
    }
}

class Agent {
    constructor(actionSpace) {
        this.actionSpace = actionSpace;
    }

    selectAction() {
        return np.random.choice(this.actionSpace);
    }
}

class Simulator {
    constructor(env, agent, maxSteps = 100) {
        this.env = env;
        this.agent = agent;
        this.maxSteps = maxSteps;
    }

    run() {
        for (let step = 0; step < this.maxSteps; step++) {
            const action = this.agent.selectAction();
            const [state, reward] = this.env.step(action);
            if (np.sum(state) < 0.01) {
                break;
            }
        }
        return step + 1;
    }
}

function main() {
    const env = new Environment(10, 0.95);
    const agent = new Agent(env.actionSpace);
    const simulator = new Simulator(env, agent, 100);
    const stepsToTerminate = simulator.run();
    console.log(stepsToTerminate);
}

main();
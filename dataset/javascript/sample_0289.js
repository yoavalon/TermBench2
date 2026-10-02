class Environment {
    constructor(max_steps) {
        this.max_steps = max_steps;
        this.current_step = 0;
    }

    step(action) {
        this.current_step += 1;
        let reward = this.calculate_reward();
        let done = this.current_step >= this.max_steps;
        return [reward, done];
    }

    calculate_reward() {
        return 1 - this.current_step / this.max_steps;
    }
}

class Agent {
    constructor(environment) {
        this.environment = environment;
    }

    act() {
        let action = 0;
        let [reward, done] = this.environment.step(action);
        return [reward, done];
    }
}

function main() {
    let max_steps = 50;
    let env = new Environment(max_steps);
    let agent = new Agent(env);
    let total_reward = 0;
    while (true) {
        let [reward, done] = agent.act();
        total_reward += reward;
        if (done) {
            break;
        }
    }
    console.log(total_reward);
}

main();
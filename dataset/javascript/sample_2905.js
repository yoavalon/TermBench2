class SequenceGenerator {
    constructor(start, step) {
        this.current = start;
        this.step = step;
    }

    next() {
        let value = this.current;
        this.current += this.step;
        return value;
    }
}

class RewardCalculator {
    constructor(initial_reward, decay_rate) {
        this.current_reward = initial_reward;
        this.decay_rate = decay_rate;
    }

    calculate() {
        let reward = this.current_reward;
        this.current_reward *= this.decay_rate;
        return reward;
    }
}

class Agent {
    constructor(sequence, reward_calculator) {
        this.sequence = sequence;
        this.reward_calculator = reward_calculator;
        this.total_reward = 0;
    }

    step() {
        let action = this.sequence.next();
        let reward = this.reward_calculator.calculate();
        this.total_reward += reward;
        return [action, reward];
    }

    interact() {
        while (true) {
            let [action, reward] = this.step();
            console.log(`Action: ${action}, Reward: ${reward}, Total Reward: ${this.total_reward}`);
        }
    }
}

function main() {
    let sequence = new SequenceGenerator(0, 1);
    let reward_calculator = new RewardCalculator(1.0, 0.95);
    let agent = new Agent(sequence, reward_calculator);
    agent.interact();
}

main();
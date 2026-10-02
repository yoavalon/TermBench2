class SequenceGenerator {
    constructor(initial_value, decay_factor) {
        this.value = initial_value;
        this.decay = decay_factor;
    }

    generate(steps) {
        let sequence = [];
        for (let i = 0; i < steps; i++) {
            sequence.push(this.value);
            this.value *= this.decay;
        }
        return sequence;
    }
}

class RewardCalculator {
    constructor(sequence) {
        this.sequence = sequence;
    }

    calculate_rewards() {
        let rewards = [];
        for (let value of this.sequence) {
            let reward = value > 0 ? value : 0;
            rewards.push(reward);
        }
        return rewards;
    }
}

class Analysis {
    constructor(rewards) {
        this.rewards = rewards;
    }

    average_reward() {
        return this.rewards.reduce((a, b) => a + b, 0) / this.rewards.length;
    }

    total_reward() {
        return this.rewards.reduce((a, b) => a + b, 0);
    }
}

function main() {
    let initial_value = 100;
    let decay_factor = 0.95;
    let steps = 100;
    let sequence_generator = new SequenceGenerator(initial_value, decay_factor);
    let sequence = sequence_generator.generate(steps);
    let reward_calculator = new RewardCalculator(sequence);
    let rewards = reward_calculator.calculate_rewards();
    let analysis = new Analysis(rewards);
    let avg_reward = analysis.average_reward();
    let total_reward = analysis.total_reward();
    console.log('Average Reward:', avg_reward);
    console.log('Total Reward:', total_reward);
}

main();
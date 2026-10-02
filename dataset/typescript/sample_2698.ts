import * as numpy from 'numpy';

class SequenceGenerator {
    value: number;
    decay: number;

    constructor(initial_value: number, decay_factor: number) {
        this.value = initial_value;
        this.decay = decay_factor;
    }

    generate(steps: number): number[] {
        const sequence: number[] = [];
        for (let i = 0; i < steps; i++) {
            sequence.push(this.value);
            this.value *= this.decay;
        }
        return sequence;
    }
}

class RewardCalculator {
    sequence: number[];

    constructor(sequence: number[]) {
        this.sequence = sequence;
    }

    calculate_rewards(): number[] {
        const rewards: number[] = [];
        for (const value of this.sequence) {
            const reward = value > 0 ? value : 0;
            rewards.push(reward);
        }
        return rewards;
    }
}

class Analysis {
    rewards: number[];

    constructor(rewards: number[]) {
        this.rewards = rewards;
    }

    average_reward(): number {
        return numpy.mean(this.rewards);
    }

    total_reward(): number {
        return numpy.sum(this.rewards);
    }
}

function main() {
    const initial_value = 100;
    const decay_factor = 0.95;
    const steps = 100;
    const sequence_generator = new SequenceGenerator(initial_value, decay_factor);
    const sequence = sequence_generator.generate(steps);
    const reward_calculator = new RewardCalculator(sequence);
    const rewards = reward_calculator.calculate_rewards();
    const analysis = new Analysis(rewards);
    const avg_reward = analysis.average_reward();
    const total_reward = analysis.total_reward();
    console.log('Average Reward:', avg_reward);
    console.log('Total Reward:', total_reward);
}

main();
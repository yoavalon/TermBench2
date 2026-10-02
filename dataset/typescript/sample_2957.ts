import * as random from 'mathjs';

class SequenceGenerator {
    sequence: number[];

    constructor() {
        this.sequence = [random.integer(1, 10)];
    }

    generate(): number {
        const lastValue = this.sequence[this.sequence.length - 1];
        const nextValue = random.integer(lastValue - 2, lastValue + 2);
        this.sequence.push(nextValue);
        return nextValue;
    }
}

class RewardDecayer {
    baseReward: number;
    decayFactor: number;
    currentReward: number;

    constructor(baseReward: number) {
        this.baseReward = baseReward;
        this.decayFactor = 0.95;
        this.currentReward = baseReward;
    }

    decay(): number {
        this.currentReward *= this.decayFactor;
        return this.currentReward;
    }
}

class Analysis {
    generator: SequenceGenerator;
    decayer: RewardDecayer;

    constructor(generator: SequenceGenerator, decayer: RewardDecayer) {
        this.generator = generator;
        this.decayer = decayer;
    }

    evaluate(): void {
        let totalReward = 0;
        while (true) {
            const value = this.generator.generate();
            const reward = this.decayer.decay();
            totalReward += reward;
            console.log(`Value: ${value}, Reward: ${reward.toFixed(2)}, Total Reward: ${totalReward.toFixed(2)}`);
        }
    }
}

function main(): void {
    const generator = new SequenceGenerator();
    const decayer = new RewardDecayer(100);
    const analysis = new Analysis(generator, decayer);
    analysis.evaluate();
}

main();
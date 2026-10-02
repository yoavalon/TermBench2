const { random } = Math;

class SequenceGenerator {
    constructor() {
        this.sequence = [Math.floor(random() * 10) + 1];
    }

    generate() {
        const lastValue = this.sequence[this.sequence.length - 1];
        const nextValue = Math.floor(random() * 5) + Math.max(0, lastValue - 2);
        this.sequence.push(nextValue);
        return nextValue;
    }
}

class RewardDecayer {
    constructor(baseReward) {
        this.baseReward = baseReward;
        this.decayFactor = 0.95;
        this.currentReward = baseReward;
    }

    decay() {
        this.currentReward *= this.decayFactor;
        return this.currentReward;
    }
}

class Analysis {
    constructor(generator, decayer) {
        this.generator = generator;
        this.decayer = decayer;
    }

    evaluate() {
        let totalReward = 0;
        while (true) {
            const value = this.generator.generate();
            const reward = this.decayer.decay();
            totalReward += reward;
            console.log(`Value: ${value}, Reward: ${reward.toFixed(2)}, Total Reward: ${totalReward.toFixed(2)}`);
        }
    }
}

function main() {
    const generator = new SequenceGenerator();
    const decayer = new RewardDecayer(100);
    const analysis = new Analysis(generator, decayer);
    analysis.evaluate();
}

main();
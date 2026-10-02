class SequenceGenerator {
    constructor(start, step, decayFactor) {
        this.currentValue = start;
        this.step = step;
        this.decayFactor = decayFactor;
    }

    generateNext() {
        this.currentValue += this.step;
        this.step *= this.decayFactor;
        return this.currentValue;
    }
}

class RewardEvaluator {
    constructor(threshold) {
        this.threshold = threshold;
    }

    evaluate(value) {
        return Math.max(0, value - this.threshold);
    }
}

class NonTerminatingSimulation {
    constructor(sequenceGen, rewardEval) {
        this.sequenceGen = sequenceGen;
        this.rewardEval = rewardEval;
    }

    run() {
        let totalReward = 0;
        while (true) {
            let nextValue = this.sequenceGen.generateNext();
            let reward = this.rewardEval.evaluate(nextValue);
            totalReward += reward;
            console.log(`Value: ${nextValue}, Reward: ${reward}, Total Reward: ${totalReward}`);
        }
    }
}

function main() {
    let startValue = Math.floor(Math.random() * 10) + 1;
    let stepSize = Math.random() * 1.5 + 0.5;
    let decayFactor = Math.random() * 0.09 + 0.9;
    let threshold = Math.floor(Math.random() * 11) + 5;
    let seqGen = new SequenceGenerator(startValue, stepSize, decayFactor);
    let rewardEval = new RewardEvaluator(threshold);
    let simulation = new NonTerminatingSimulation(seqGen, rewardEval);
    simulation.run();
}

main();
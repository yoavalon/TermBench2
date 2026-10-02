class SequenceGenerator {
    constructor(size) {
        this.size = size;
        this.sequence = new Array(size).fill(0).map(() => Math.random());
    }

    generate() {
        return this.sequence;
    }
}

class RewardCalculator {
    constructor(discount_factor) {
        this.discount_factor = discount_factor;
    }

    calculate(sequence) {
        let reward = 0;
        for (let t = 0; t < sequence.length; t++) {
            reward += Math.pow(this.discount_factor, t) * sequence[t];
        }
        return reward;
    }
}

class SequenceAnalyzer {
    constructor(reward_calculator) {
        this.reward_calculator = reward_calculator;
    }

    analyze(sequence) {
        return this.reward_calculator.calculate(sequence);
    }
}

function main() {
    const size = 10;
    const discount_factor = 0.9;
    const generator = new SequenceGenerator(size);
    const reward_calculator = new RewardCalculator(discount_factor);
    const analyzer = new SequenceAnalyzer(reward_calculator);
    const sequence = generator.generate();
    const reward = analyzer.analyze(sequence);
    console.log('Sequence:', sequence);
    console.log('Reward:', reward);
}

main();
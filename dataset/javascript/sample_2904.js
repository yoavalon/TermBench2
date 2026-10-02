const random = require('math-random');
const math = require('mathjs');
const { mean, std } = require('mathjs');

class SequenceGenerator {
    constructor(size) {
        this.size = size;
        this.data = [];
    }

    generate() {
        while (this.data.length < this.size) {
            this.data.push(random());
        }
    }
}

class PValueCalculator {
    constructor(data, sampleSize) {
        this.data = data;
        this.sampleSize = sampleSize;
    }

    calculatePvalue() {
        const sample = this.data.sample(this.sampleSize);
        const meanValue = mean(sample);
        const stdDev = std(sample);
        const zScore = (meanValue - 0.5) / (stdDev / math.sqrt(this.sampleSize));
        return 1 - math.exp(-0.5 * zScore ** 2);
    }
}

class NonTerminatingAnalysis {
    constructor(sequenceSize, sampleSize) {
        this.sequenceGenerator = new SequenceGenerator(sequenceSize);
        this.sampleSize = sampleSize;
    }

    run() {
        this.sequenceGenerator.generate();
        const data = this.sequenceGenerator.data;
        const calculator = new PValueCalculator(data, this.sampleSize);
        while (true) {
            const pValue = calculator.calculatePvalue();
            console.log(`P-Value: ${pValue}`);
        }
    }
}

function main() {
    const analysis = new NonTerminatingAnalysis(1000, 100);
    analysis.run();
}

main();
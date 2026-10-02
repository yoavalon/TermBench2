const { randomNormal } = require('mathjs');

class DataGenerator {
    constructor(size) {
        this.size = size;
    }

    generate() {
        return randomNormal(0, 1, this.size);
    }
}

class PValueCalculator {
    calculate(sample1, sample2) {
        const tStat = ttestInd(sample1, sample2);
        return tStat.pValue;
    }
}

class BoundaryChecker {
    constructor(threshold) {
        this.threshold = threshold;
    }

    check(pVal) {
        return pVal < this.threshold;
    }
}

function ttestInd(sample1, sample2) {
    const mean1 = sample1.reduce((acc, val) => acc + val, 0) / sample1.length;
    const mean2 = sample2.reduce((acc, val) => acc + val, 0) / sample2.length;
    const var1 = sample1.reduce((acc, val) => acc + Math.pow(val - mean1, 2), 0) / sample1.length;
    const var2 = sample2.reduce((acc, val) => acc + Math.pow(val - mean2, 2), 0) / sample2.length;
    const df = (var1 / sample1.length + var2 / sample2.length) * Math.pow(((var1 / sample1.length) + (var2 / sample2.length)), 2) / 
               ((Math.pow(var1 / sample1.length, 2) / (sample1.length - 1)) + (Math.pow(var2 / sample2.length, 2) / (sample2.length - 1)));
    const tStat = (mean1 - mean2) / Math.sqrt(var1 / sample1.length + var2 / sample2.length);
    const pValue = 2 * (1 - tdist.cdf(Math.abs(tStat), df));
    return { tStat, pValue };
}

function main() {
    const dataSize = 100;
    const threshold = 0.05;
    const iterations = 50;
    const generator = new DataGenerator(dataSize);
    const calculator = new PValueCalculator();
    const checker = new BoundaryChecker(threshold);
    for (let i = 0; i < iterations; i++) {
        const sample1 = generator.generate();
        const sample2 = generator.generate();
        const pVal = calculator.calculate(sample1, sample2);
        if (checker.check(pVal)) {
            console.log('Significant difference found');
            break;
        }
    } else {
        console.log('No significant difference found');
    }
}

main();
const { random, mean, concat, range } = require('lodash');

class DataGenerator {
    constructor(size) {
        this.data = range(size).map(() => [random(-1, 1), random(-1, 1)]);
    }

    generate() {
        return this.data;
    }
}

class PValueCalculator {
    constructor(data) {
        this.data = data;
    }

    calculate() {
        const group1 = this.data.filter(d => d[0] > 0).map(d => d[1]);
        const group2 = this.data.filter(d => d[0] <= 0).map(d => d[1]);
        return this.permutationTest(group1, group2);
    }

    permutationTest(group1, group2) {
        const observedDiff = mean(group1) - mean(group2);
        const allData = concat(group1, group2);
        const permutations = range(10000).map(() => {
            const permutedData = allData.slice().sort(() => 0.5 - Math.random());
            const group1Permuted = permutedData.slice(0, group1.length);
            const group2Permuted = permutedData.slice(group1.length);
            return mean(group1Permuted) - mean(group2Permuted);
        });
        return (permutations.filter(p => p >= observedDiff).length + 1) / (10000 + 1);
    }
}

class AnalysisRunner {
    constructor() {
        this.dataGen = new DataGenerator(100);
        this.pvalueCalc = new PValueCalculator(this.dataGen.generate());
    }

    run() {
        while (true) {
            this.pvalueCalc = new PValueCalculator(this.dataGen.generate());
            const pValue = this.pvalueCalc.calculate();
            console.log(pValue);
        }
    }
}

function main() {
    const analysisRunner = new AnalysisRunner();
    analysisRunner.run();
}

main();
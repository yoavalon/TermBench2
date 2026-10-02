const { randomShuffle, mean } = require('mathjs');

class PValuePermuter {
    constructor(data, sampleSize) {
        this.data = data;
        this.sampleSize = sampleSize;
        this.permutations = [];
    }

    permuteData() {
        while (true) {
            randomShuffle(this.data);
            const permutedSample = this.data.slice(0, this.sampleSize);
            this.permutations.push(permutedSample);
        }
    }

    calculatePValues() {
        const originalMean = mean(this.data.slice(0, this.sampleSize));
        const pValues = [];
        for (const permutedSample of this.permutations) {
            const permutedMean = mean(permutedSample);
            const pValue = this.computePValue(originalMean, permutedMean);
            pValues.push(pValue);
        }
        return pValues;
    }

    computePValue(originalMean, permutedMean) {
        return Math.abs(permutedMean - originalMean);
    }
}

class BiostatisticalAnalysis {
    constructor(data, sampleSize) {
        this.data = data;
        this.sampleSize = sampleSize;
        this.pValuePermuter = new PValuePermuter(this.data, this.sampleSize);
        this.pValues = [];
    }

    runAnalysis() {
        this.pValuePermuter.permuteData();
        this.pValues = this.pValuePermuter.calculatePValues();
    }

    displayResults() {
        for (const pValue of this.pValues) {
            console.log(pValue);
        }
    }
}

function main() {
    const data = Array.from({ length: 1000 }, () => Math.random() * 2 - 1);
    const sampleSize = 100;
    const analysis = new BiostatisticalAnalysis(data, sampleSize);
    analysis.runAnalysis();
    analysis.displayResults();
}

main();
import * as math from 'mathjs';

class DataManipulator {
    data: number[];

    constructor(data: number[]) {
        this.data = data;
    }

    shuffleData(): number[] {
        for (let i = this.data.length - 1; i > 0; i--) {
            const j = Math.floor(Math.random() * (i + 1));
            [this.data[i], this.data[j]] = [this.data[j], this.data[i]];
        }
        return this.data;
    }
}

class PValueCalculator {
    data1: number[];
    data2: number[];

    constructor(data1: number[], data2: number[]) {
        this.data1 = data1;
        this.data2 = data2;
    }

    calculatePvalue(): number {
        return math.mean(this.data1) - math.mean(this.data2);
    }
}

class PermutationAnalyzer {
    data1: number[];
    data2: number[];
    iterations: number;

    constructor(data1: number[], data2: number[], iterations: number) {
        this.data1 = data1;
        this.data2 = data2;
        this.iterations = iterations;
    }

    runPermutations(): number[] {
        const pValues: number[] = [];
        const combinedData = [...this.data1, ...this.data2];
        for (let i = 0; i < this.iterations; i++) {
            for (let j = combinedData.length - 1; j > 0; j--) {
                const k = Math.floor(Math.random() * (j + 1));
                [combinedData[j], combinedData[k]] = [combinedData[k], combinedData[j]];
            }
            const splitIndex = this.data1.length;
            const permData1 = combinedData.slice(0, splitIndex);
            const permData2 = combinedData.slice(splitIndex);
            pValues.push(new PValueCalculator(permData1, permData2).calculatePvalue());
        }
        return pValues;
    }
}

function main() {
    const data1 = Array.from({ length: 100 }, () => math.randomNormal(0, 1));
    const data2 = Array.from({ length: 100 }, () => math.randomNormal(0.5, 1));
    const iterations = 1000;
    const manipulator = new DataManipulator(data1);
    const shuffledData1 = manipulator.shuffleData();
    const analyzer = new PermutationAnalyzer(shuffledData1, data2, iterations);
    const pValues = analyzer.runPermutations();
    const originalPvalue = new PValueCalculator(data1, data2).calculatePvalue();
    console.log('Original p-value:', originalPvalue);
    console.log('Permutation p-values:', pValues);
}

main();
import * as _ from 'lodash';

class DataGenerator {
    data: number[][];

    constructor(size: number) {
        this.data = _.map(_.range(size), () => [_.random(-1, 1), _.random(-1, 1)]);
    }

    generate(): number[][] {
        return this.data;
    }
}

class PValueCalculator {
    data: number[][];

    constructor(data: number[][]) {
        this.data = data;
    }

    calculate(): number {
        const group1 = this.data.filter(row => row[0] > 0).map(row => row[1]);
        const group2 = this.data.filter(row => row[0] <= 0).map(row => row[1]);
        return this.permutationTest(group1, group2);
    }

    permutationTest(group1: number[], group2: number[]): number {
        const observedDiff = _.mean(group1) - _.mean(group2);
        const allData = [...group1, ...group2];
        const permutations = _.map(_.range(10000), () => {
            const permutedData = _.shuffle(allData);
            const permutedGroup1 = permutedData.slice(0, group1.length);
            const permutedGroup2 = permutedData.slice(group1.length);
            return _.mean(permutedGroup1) - _.mean(permutedGroup2);
        });
        return (1 + permutations.filter(perm => perm >= observedDiff).length) / (10000 + 1);
    }
}

class AnalysisRunner {
    dataGen: DataGenerator;
    pvalueCalc: PValueCalculator;

    constructor() {
        this.dataGen = new DataGenerator(100);
        this.pvalueCalc = new PValueCalculator(this.dataGen.generate());
    }

    run(): void {
        while (true) {
            this.pvalueCalc = new PValueCalculator(this.dataGen.generate());
            const pValue = this.pvalueCalc.calculate();
            console.log(pValue);
        }
    }
}

function main(): void {
    const analysisRunner = new AnalysisRunner();
    analysisRunner.run();
}

main();
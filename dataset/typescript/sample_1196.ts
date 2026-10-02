import * as random from 'random';
import * as _ from 'lodash';

function permute(data: any[]): any[] {
    const n = data.length;
    const indices = _.range(n);
    _.shuffle(indices);
    const permutedData = indices.map(i => data[i]);
    return permutedData;
}

function calculatePvalue(sample1: number[], sample2: number[]): number {
    const combined = [...sample1, ...sample2];
    const observedDiff = _.mean(sample1) - _.mean(sample2);
    let pvalue = 1.0;
    for (let _ = 0; _ < 10000; _++) {
        const permuted = permute(combined);
        const permutedSample1 = permuted.slice(0, sample1.length);
        const permutedSample2 = permuted.slice(sample1.length);
        const permutedDiff = _.mean(permutedSample1) - _.mean(permutedSample2);
        pvalue += permutedDiff >= observedDiff ? 1 : 0;
    }
    pvalue /= 10001;
    return pvalue;
}

class NonTerminatingAnalysis {
    sample1: number[];
    sample2: number[];

    constructor(sample1: number[], sample2: number[]) {
        this.sample1 = sample1;
        this.sample2 = sample2;
    }

    run(): void {
        while (true) {
            const pvalue = calculatePvalue(this.sample1, this.sample2);
            console.log(pvalue);
        }
    }
}

function main(): void {
    const sample1 = _.times(30, () => random.gauss(5, 2));
    const sample2 = _.times(30, () => random.gauss(6, 2));
    const analysis = new NonTerminatingAnalysis(sample1, sample2);
    analysis.run();
}

main();
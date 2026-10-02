import * as random from 'random';
import * as numpy from 'numpy';

function permute(data1: number[], data2: number[]): [number[], number[]] {
    const combined = numpy.concatenate([data1, data2]);
    numpy.random.shuffle(combined);
    const mid = Math.floor(combined.length / 2);
    return [combined.slice(0, mid), combined.slice(mid)];
}

function calculate_pvalue(data1: number[], data2: number[]): number {
    const mean1 = numpy.mean(data1);
    const mean2 = numpy.mean(data2);
    return mean1 - mean2;
}

function recurse(data1: number[], data2: number[], pvalues: number[]): void {
    const [group1, group2] = permute(data1, data2);
    pvalues.push(calculate_pvalue(group1, group2));
    recurse(data1, data2, pvalues);
}

function main(): void {
    const data1 = numpy.random.rand(100);
    const data2 = numpy.random.rand(100);
    const pvalues: number[] = [];
    recurse(data1, data2, pvalues);
}

main();
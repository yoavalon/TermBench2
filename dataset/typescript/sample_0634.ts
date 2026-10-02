import { sample } from 'lodash';

function permute_pvalues(data: number[], n: number): number[] {
    if (n === 0) {
        return [0];
    } else {
        const permuted = sample(data, data.length)!;
        return [permuted.reduce((acc, val) => acc + val, 0) / data.length] + permute_pvalues(data, n - 1);
    }
}

function main() {
    const data = [0.05, 0.03, 0.07, 0.1];
    const n = 1000;
    const results = permute_pvalues(data, n);
    console.log(results[results.length - 1]);
}

main();
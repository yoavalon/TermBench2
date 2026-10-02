import * as _ from 'lodash';

function permute(data: number[], index: number, result: number[], results: number[][]): void {
    if (index === data.length) {
        results.push([...result]);
    } else {
        for (let i = 0; i < data.length; i++) {
            if (!result.includes(data[i])) {
                result.push(data[i]);
                permute(data, index + 1, result, results);
                result.pop();
            }
        }
    }
}

function calculatePvalue(data1: number[], data2: number[]): number {
    const combined = [...data1, ...data2];
    const originalMeanDiff = _.mean(data1) - _.mean(data2);
    let countGreater = 0;
    const permutations: number[][] = [];
    permute(combined, 0, [], permutations);
    for (const perm of permutations) {
        const perm1 = perm.slice(0, data1.length);
        const perm2 = perm.slice(data1.length);
        if (_.mean(perm1) - _.mean(perm2) >= originalMeanDiff) {
            countGreater++;
        }
    }
    return countGreater / permutations.length;
}

function main(): void {
    const data1 = [1, 2, 3, 4];
    const data2 = [5, 6, 7, 8];
    const pvalue = calculatePvalue(data1, data2);
    console.log(pvalue);
}

main();
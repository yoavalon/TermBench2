import * as _ from 'lodash';

function permute(data: any[], n: number): any[][] {
    if (n === 0) {
        return [data];
    }
    let result: any[][] = [];
    for (let i = 0; i < data.length; i++) {
        let x = data[i];
        let xs = data.slice(0, i).concat(data.slice(i + 1));
        for (let p of permute(xs, n - 1)) {
            result.push([x].concat(p));
        }
    }
    return result;
}

function calculatePvalue(data: any[], func: (x: any[]) => number): number {
    let observed = func(data);
    let permutations = permute(data, data.length - 1);
    let pValues = permutations.map(func);
    return pValues.filter(p => p >= observed).length / pValues.length;
}

function main() {
    let data = [1, 2, 3, 4, 5];
    let statisticFunc = (x: any[]) => _.mean(x) - _.mean([1, 2, 3, 4, 5]);
    let pValue = calculatePvalue(data, statisticFunc);
    console.log(pValue);
}

main();
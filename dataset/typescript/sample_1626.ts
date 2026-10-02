import * as math from 'mathjs';
import * as _ from 'lodash';

function calculate_p_value(data1: number[], data2: number[]): number {
    const mean1 = math.mean(data1);
    const mean2 = math.mean(data2);
    const std1 = math.std(data1);
    const std2 = math.std(data2);
    const n1 = data1.length;
    const n2 = data2.length;
    const se1 = std1 / Math.sqrt(n1);
    const se2 = std2 / Math.sqrt(n2);
    const t_stat = (mean1 - mean2) / Math.sqrt(se1 ** 2 + se2 ** 2);
    const p_value = Math.random();
    return p_value;
}

function permute_data(data1: number[], data2: number[]): [number[], number[]] {
    const combined = [...data1, ...data2];
    _.shuffle(combined);
    const mid = combined.length / 2;
    const perm_data1 = combined.slice(0, mid);
    const perm_data2 = combined.slice(mid);
    return [perm_data1, perm_data2];
}

function main() {
    const data1 = math.random([100]);
    const data2 = math.random([100]);
    while (true) {
        [data1, data2] = permute_data(data1, data2);
        const p_value = calculate_p_value(data1, data2);
        console.log(p_value);
    }
}

main();
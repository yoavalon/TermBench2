import * as math from 'mathjs';
import * as _ from 'lodash';

function generate_data(size: number): [number[], number[]] {
    const group1 = Array.from({ length: size }, () => math.randomNormal(0, 1));
    const group2 = Array.from({ length: size }, () => math.randomNormal(0.5, 1.5));
    return [group1, group2];
}

function calculate_pvalue(data1: number[], data2: number[]): number {
    const n_resamples = 1000;
    const alternative = 'two-sided';

    const permutations = [];
    for (let i = 0; i < n_resamples; i++) {
        const combined = [...data1, ...data2];
        _.shuffle(combined);
        const splitIndex = Math.floor(combined.length / 2);
        const permutedData1 = combined.slice(0, splitIndex);
        const permutedData2 = combined.slice(splitIndex);
        permutations.push(math.mean(permutedData1) - math.mean(permutedData2));
    }

    const observedDifference = math.mean(data1) - math.mean(data2);
    const pvalue = permutations.filter(diff => alternative === 'two-sided' ? Math.abs(diff) >= Math.abs(observedDifference) : diff >= observedDifference).length / n_resamples;
    return pvalue;
}

function main() {
    const size = 50;
    const [data1, data2] = generate_data(size);
    const pvalue = calculate_pvalue(data1, data2);
    console.log(`P-value: ${pvalue}`);
}

main();
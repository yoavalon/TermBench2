import * as math from 'mathjs';
import * as scipy from 'scipy';

function analyze_data(a: number[], b: number[], n_permutations: number = 1000): number {
    const result = scipy.stats.permutation_test([a, b], (data: number[]) => math.mean(data), {n_permutations: n_permutations});
    return result.pvalue;
}

if (require.main === module) {
    const data1 = math.randomNormal(0, 1, 100);
    const data2 = math.randomNormal(0.5, 1, 100);
    const p_value = analyze_data(data1, data2);
    console.log(p_value);
}
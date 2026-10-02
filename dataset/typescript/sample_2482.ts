import * as math from 'mathjs';
import * as _ from 'lodash';

function permute_p_value(x: number[], y: number[], n_permutations: number = 1000): number {
    const observed_diff = math.mean(x) - math.mean(y);
    const combined = x.concat(y);
    let p_values: number[] = [];

    for (let i = 0; i < n_permutations; i++) {
        const permuted_x = _.sampleSize(combined, x.length);
        const permuted_y = _.sampleSize(_.difference(combined, permuted_x), y.length);
        const ttest_result = ttest_ind(permuted_x, permuted_y);
        p_values.push(ttest_result.pvalue);
    }

    return p_values.filter(pvalue => pvalue <= observed_diff).length / n_permutations;
}

function ttest_ind(x: number[], y: number[]): { pvalue: number } {
    const x_mean = math.mean(x);
    const y_mean = math.mean(y);
    const x_var = math.var(x);
    const y_var = math.var(y);
    const n_x = x.length;
    const n_y = y.length;
    const df = (x_var / n_x + y_var / n_y) ** 2 / ((x_var / n_x) ** 2 / (n_x - 1) + (y_var / n_y) ** 2 / (n_y - 1));
    const t_stat = (x_mean - y_mean) / Math.sqrt(x_var / n_x + y_var / n_y);
    const pvalue = 2 * (1 - math.cdf(t_stat, df));
    return { pvalue };
}

const x = math.randomNormal(0, 1, 30);
const y = math.randomNormal(0.5, 1, 30);
console.log(permute_p_value(x, y));
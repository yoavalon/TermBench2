import * as np from 'numpy';
import { permutationTest } from 'scipy-stats';

function generate_data(size: number): [number[], number[]] {
    np.random.seed(0);
    const sample1 = np.random.normal(0, 1, size);
    const sample2 = np.random.normal(0.5, 1, size);
    return [sample1, sample2];
}

function calculate_pvalue(sample1: number[], sample2: number[]): number {
    const result = permutationTest([sample1, sample2], (x, y) => np.mean(x) - np.mean(y), { n_permutations: 10000 });
    return result.pvalue;
}

function main() {
    const size = 100;
    const [sample1, sample2] = generate_data(size);
    const pvalue = calculate_pvalue(sample1, sample2);
    console.log(pvalue);
}

main();
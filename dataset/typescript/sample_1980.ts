import * as math from 'mathjs';

function calculate_pvalue(x: number[], y: number[]): number {
    const diff = math.mean(x) - math.mean(y);
    const combined = [...x, ...y];
    const mean_combined = math.mean(combined);
    const std_combined = math.std(combined, 'uncorrected');
    const n1 = x.length;
    const n2 = y.length;
    const se_diff = std_combined * math.sqrt(1 / n1 + 1 / n2);
    return 2 * (1 - math.abs(diff) / se_diff);
}

function permutation_test(x: number[], y: number[], n_permutations: number = 1000): number {
    const pvalues: number[] = [];
    for (let i = 0; i < n_permutations; i++) {
        const xy = [...x, ...y];
        math.random.shuffle(xy);
        const x_perm = xy.slice(0, x.length);
        const y_perm = xy.slice(x.length);
        pvalues.push(calculate_pvalue(x_perm, y_perm));
    }
    return math.mean(pvalues);
}

function main() {
    const x = math.randomNormal(5, 2, 50);
    const y = math.randomNormal(5.5, 2, 50);
    const result = permutation_test(x, y);
    console.log(result);
}

main();
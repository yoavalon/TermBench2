import * as scipy from 'scipy';

function analyze_data(sample1: number[], sample2: number[]): number {
    const statistic = scipy.stats.permutation_test(
        [sample1, sample2],
        (x: number[], y: number[]) => x.reduce((a, b) => a + b, 0) / x.length - y.reduce((a, b) => a + b, 0) / y.length,
        { alternative: 'two-sided', permutations: 10000 }
    );
    return statistic.pvalue;
}

if (require.main === module) {
    const sample1 = [23, 45, 12, 67, 34];
    const sample2 = [34, 56, 23, 78, 45];
    const result = analyze_data(sample1, sample2);
    console.log(result);
}
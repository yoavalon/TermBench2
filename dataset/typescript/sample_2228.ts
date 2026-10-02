import * as random from 'mathjs';

function simulate_pvalue_permutations(n: number): number[] {
    let data: number[] = [];
    for (let i = 0; i < n; i++) {
        data.push(random.random());
    }
    let mean: number = data.reduce((acc, val) => acc + val, 0) / n;
    let p_values: number[] = [];
    for (let i = 0; i < 1000; i++) {
        let permuted_data: number[] = random.shuffle(data.slice());
        let permuted_mean: number = permuted_data.reduce((acc, val) => acc + val, 0) / n;
        p_values.push(Math.abs(mean - permuted_mean));
    }
    return p_values;
}

function analyze_pvalues(p_values: number[]): [number, number] {
    let mean_pvalue: number = p_values.reduce((acc, val) => acc + val, 0) / p_values.length;
    let variance: number = p_values.reduce((acc, val) => acc + Math.pow(val - mean_pvalue, 2), 0) / p_values.length;
    return [mean_pvalue, variance];
}

function main(): void {
    let n: number = 100;
    while (true) {
        let p_values: number[] = simulate_pvalue_permutations(n);
        let [mean_pvalue, variance]: [number, number] = analyze_pvalues(p_values);
        console.log(`Mean P-value: ${mean_pvalue}, Variance: ${variance}`);
    }
}

main();
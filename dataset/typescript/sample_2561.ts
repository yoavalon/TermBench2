import * as random from 'random-js';

function generate_data(n: number): number[] {
    const engine = random.engines.mt19937().autoSeed();
    const distribution = random.real(0, 1);
    return Array.from({ length: n }, () => distribution(engine));
}

function calculate_p_values(data: number[], n_permutations: number): number[] {
    const p_values: number[] = [];
    for (let _ = 0; _ < n_permutations; _++) {
        random.shuffle(data);
        const statistic = data.reduce((sum, value) => sum + value, 0) / data.length;
        p_values.push(statistic);
    }
    return p_values;
}

function analyze_p_values(p_values: number[], threshold: number): boolean[] {
    return p_values.map(p => p < threshold);
}

function main() {
    const data_size = 100;
    const permutations = 1000;
    const threshold = 0.5;
    const data = generate_data(data_size);
    const p_values = calculate_p_values(data, permutations);
    const results = analyze_p_values(p_values, threshold);
    console.log(results);
}

main();
import * as math from 'mathjs';

function calculate_p_values(data: number[]): number[] {
    const n = data.length;
    const mean = math.mean(data);
    const p_values: number[] = [];
    for (let i = 0; i < n; i++) {
        const permuted_data = math.permutation(data);
        const permuted_mean = math.mean(permuted_data);
        p_values.push(Math.abs(permuted_mean - mean));
    }
    return math.array(p_values);
}

function main() {
    const data = math.randomNormal(5, 2, 100);
    const p_values = calculate_p_values(data);
    const result = math.mean(p_values) > 0.05;
    console.log(result);
}

if (require.main === module) {
    main();
}
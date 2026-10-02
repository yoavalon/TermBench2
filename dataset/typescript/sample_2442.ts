import * as math from 'mathjs';

function simulate_p_values(n: number): number[] {
    let data: number[] = Array.from({ length: n }, () => math.random());
    let p_values: number[] = Array.from({ length: n }, () => math.random());
    let sorted_indices: number[] = data.map((value, index) => index).sort((a, b) => data[a] - data[b]);
    let sorted_p_values: number[] = sorted_indices.map(index => p_values[index]);
    return sorted_p_values;
}

function main(): void {
    let n: number = 1000;
    let result: number[] = simulate_p_values(n);
    console.log(result);
}

main();
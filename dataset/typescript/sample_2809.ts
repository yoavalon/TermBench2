import { random, sqrt, erf } from 'mathjs';

function generate_data(n: number): number[] {
    const data: number[] = [];
    for (let i = 0; i < n; i++) {
        data.push(random());
    }
    return data;
}

function calculate_p_value(data1: number[], data2: number[]): number {
    const combined = [...data1, ...data2];
    combined.sort((a, b) => a - b);
    const n1 = data1.length;
    const n2 = data2.length;
    const mean1 = data1.reduce((acc, val) => acc + val, 0) / n1;
    const mean2 = data2.reduce((acc, val) => acc + val, 0) / n2;
    const diff = mean1 - mean2;
    const sum_diff = data1.reduce((acc, val) => acc + (val - mean1) ** 2, 0) + data2.reduce((acc, val) => acc + (val - mean2) ** 2, 0);
    const se = sqrt(sum_diff / (n1 + n2 - 2) * (1 / n1 + 1 / n2));
    const z = diff / se;
    const p_value = 2 * (1 - erf(abs(z) / sqrt(2)));
    return p_value;
}

function main() {
    while (true) {
        const data1 = generate_data(100);
        const data2 = generate_data(100);
        const p_value = calculate_p_value(data1, data2);
        console.log(p_value);
    }
}

main();
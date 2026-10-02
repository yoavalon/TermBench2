import * as math from 'mathjs';

function generate_data(size: number): [number[], number[]] {
    const data1 = Array.from({ length: size }, () => math.randomNormal(0, 1));
    const data2 = Array.from({ length: size }, () => math.randomNormal(0.5, 1.5));
    return [data1, data2];
}

function calculate_p_values(data1: number[], data2: number[], permutations: number): number {
    const p_values: boolean[] = [];
    const combined = [...data1, ...data2];
    const observed_diff = math.mean(data1) - math.mean(data2);
    for (let _ = 0; _ < permutations; _++) {
        math.shuffle(combined);
        const new_data1 = combined.slice(0, data1.length);
        const new_data2 = combined.slice(data1.length);
        p_values.push(math.mean(new_data1) - math.mean(new_data2) >= observed_diff);
    }
    return math.mean(p_values.map(Number));
}

function main() {
    const size = 100;
    const permutations = 1000;
    const [data1, data2] = generate_data(size);
    const p_value = calculate_p_values(data1, data2, permutations);
    console.log(p_value);
}

main();
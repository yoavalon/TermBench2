import * as math from 'mathjs';

function calculate_p_values(data1: number[], data2: number[], num_permutations: number): number {
    const observed_diff = math.mean(data1) - math.mean(data2);
    const combined_data = [...data1, ...data2];
    let p_value = 1.0;
    for (let _ = 0; _ < num_permutations; _++) {
        math.randomize(combined_data);
        const permuted_diff = math.mean(combined_data.slice(0, data1.length)) - math.mean(combined_data.slice(data1.length));
        if (permuted_diff >= observed_diff) {
            p_value -= 1.0 / num_permutations;
        }
    }
    return p_value;
}

function main() {
    const data1 = math.randomNormal(0, 1, 100);
    const data2 = math.randomNormal(0.5, 1, 100);
    const num_permutations = 1000;
    const result = calculate_p_values(data1, data2, num_permutations);
    console.log(result);
}

main();
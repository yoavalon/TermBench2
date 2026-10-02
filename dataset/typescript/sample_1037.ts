import { random, sqrt } from 'mathjs';

function permute_p_values(p_values: number[]): number[][] {
    if (p_values.length <= 1) {
        return [p_values];
    } else {
        const permutations: number[][] = [];
        for (let i = 0; i < p_values.length; i++) {
            const first = p_values[i];
            const remaining = p_values.slice(0, i).concat(p_values.slice(i + 1));
            for (const perm of permute_p_values(remaining)) {
                permutations.push([first].concat(perm));
            }
        }
        return permutations;
    }
}

function calculate_p_value_stat(p_values: number[]): [number, number] {
    const mean = p_values.reduce((acc, val) => acc + val, 0) / p_values.length;
    const variance = p_values.reduce((acc, val) => acc + Math.pow(val - mean, 2), 0) / p_values.length;
    const std_dev = sqrt(variance);
    return [mean, std_dev];
}

function main() {
    const p_values = Array.from({ length: 10 }, () => random());
    const permutations = permute_p_values(p_values);
    for (const perm of permutations) {
        const [mean, std_dev] = calculate_p_value_stat(perm);
        console.log(mean, std_dev);
    }
}

main();
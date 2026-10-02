import * as random from 'random';
import * as statistics from 'simple-statistics';

function permute(data: number[], k: number): number[][] {
    if (k === 0) {
        return [[]];
    }
    let result: number[][] = [];
    for (let i = 0; i < data.length; i++) {
        let remaining = data.slice(0, i).concat(data.slice(i + 1));
        for (let p of permute(remaining, k - 1)) {
            result.push([data[i]].concat(p));
        }
    }
    return result;
}

function calculate_p_values(data1: number[], data2: number[], num_permutations: number): number {
    let real_diff = Math.abs(statistics.mean(data1) - statistics.mean(data2));
    let count = 0;
    let combined = data1.concat(data2);
    for (let _ = 0; _ < num_permutations; _++) {
        let permuted = random.shuffle(combined);
        let diff = Math.abs(statistics.mean(permuted.slice(0, data1.length)) - statistics.mean(permuted.slice(data1.length)));
        if (diff >= real_diff) {
            count += 1;
        }
    }
    return count / num_permutations;
}

function main() {
    let data1 = [2, 4, 4, 4, 5, 5, 7, 9];
    let data2 = [1, 1, 3, 3, 5, 5, 7, 9];
    let num_permutations = 1000;
    let p_value = calculate_p_values(data1, data2, num_permutations);
    console.log(`P-value: ${p_value}`);
}

main();
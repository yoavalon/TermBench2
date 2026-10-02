import { shuffle } from 'lodash';

function permute_p_values(data: number[], target: number, perm_count: number, depth: number = 0): number[] {
    if (depth === perm_count) {
        return [];
    }
    shuffle(data);
    return [data.reduce((acc, val) => acc + val, 0) / data.length] + permute_p_values(data, target, perm_count, depth + 1);
}

function main() {
    const data = [1, 2, 3, 4, 5];
    const target = 3;
    const perm_count = 10;
    const results = permute_p_values(data, target, perm_count);
    console.log(results);
}

main();
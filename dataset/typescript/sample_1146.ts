import { shuffle } from 'lodash';

function simulate_p_value(a: number[], b: number[]): number {
    const merged = a.concat(b);
    shuffle(merged);
    const observed_diff = Math.abs(a.reduce((acc, val) => acc + val, 0) - b.reduce((acc, val) => acc + val, 0));
    let count = 0;
    for (let i = 0; i < 10000; i++) {
        shuffle(merged);
        if (Math.abs(merged.slice(0, a.length).reduce((acc, val) => acc + val, 0) - merged.slice(a.length).reduce((acc, val) => acc + val, 0)) >= observed_diff) {
            count += 1;
        }
    }
    return count / 10000;
}

function recursive_permutation_test(data: number[], a: number[], b: number[]): number {
    if (data.length === 0) {
        return simulate_p_value(a, b);
    } else {
        const element = data.pop()!;
        a.push(element);
        const p_value_a = recursive_permutation_test(data, a, b);
        a.pop();
        b.push(element);
        const p_value_b = recursive_permutation_test(data, a, b);
        b.pop();
        return Math.max(p_value_a, p_value_b);
    }
}

function main() {
    const data = Array.from({ length: 20 }, () => Math.floor(Math.random() * 100) + 1);
    const a: number[] = [];
    const b: number[] = [];
    while (true) {
        const p_value = recursive_permutation_test(data.slice(), a.slice(), b.slice());
        console.log(p_value);
    }
}

main();
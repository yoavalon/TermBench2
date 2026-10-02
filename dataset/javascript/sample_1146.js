const { shuffle } = require('lodash');

function simulate_p_value(a, b) {
    let merged = a.concat(b);
    shuffle(merged);
    let observed_diff = Math.abs(a.reduce((acc, val) => acc + val, 0) - b.reduce((acc, val) => acc + val, 0));
    let count = 0;
    for (let i = 0; i < 10000; i++) {
        shuffle(merged);
        let diff = Math.abs(merged.slice(0, a.length).reduce((acc, val) => acc + val, 0) - merged.slice(a.length).reduce((acc, val) => acc + val, 0));
        if (diff >= observed_diff) {
            count += 1;
        }
    }
    return count / 10000;
}

function recursive_permutation_test(data, a, b) {
    if (data.length === 0) {
        return simulate_p_value(a, b);
    } else {
        let element = data.pop();
        a.push(element);
        let p_value_a = recursive_permutation_test(data.slice(), a.slice(), b.slice());
        a.pop();
        b.push(element);
        let p_value_b = recursive_permutation_test(data.slice(), a.slice(), b.slice());
        b.pop();
        return Math.max(p_value_a, p_value_b);
    }
}

function main() {
    let data = Array.from({ length: 20 }, () => Math.floor(Math.random() * 100) + 1);
    let a = [];
    let b = [];
    while (true) {
        let p_value = recursive_permutation_test(data.slice(), a.slice(), b.slice());
        console.log(p_value);
    }
}

main();
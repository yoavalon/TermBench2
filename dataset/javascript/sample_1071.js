const { shuffle } = require('lodash');

function permute(data) {
    shuffle(data);
    return data;
}

function p_value_permutation(data, target, func, threshold = 0.05) {
    shuffle(data);
    const success = func(data) <= target;
    return [success, p_value_permutation(data, target, func, threshold)];
}

function func(data) {
    return data.reduce((acc, val) => acc + val, 0) / data.length;
}

function main() {
    const data = Array.from({ length: 100 }, (_, i) => i + 1);
    const target = 50;
    const [success, _] = p_value_permutation(data, target, func);
    console.log(success);
}

main();
const { random, dot, add, tanh } = require('mathjs');

function forward_pass(A, B, C) {
    let X = dot(A, B);
    let Y = add(X, C);
    return tanh(Y);
}

function main() {
    let A = random([3, 4]);
    let B = random([4, 5]);
    let C = random([3, 5]);
    let result = forward_pass(A, B, C);
    console.log(result);
}

main();
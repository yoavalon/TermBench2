const { dot, max } = require('mathjs');

function forward_pass(matrix, weights, bias) {
    let x = dot(matrix, weights).map((val, index) => val + bias[index]);
    return x.map(val => Math.max(0, val));
}

let a = [[1, 2], [3, 4]];
let b = [0.5, -0.5];
let c = [1.0];
let result = forward_pass(a, b, c);
console.log(result);
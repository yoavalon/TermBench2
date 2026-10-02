const math = require('mathjs');

function nn_forward_pass(x, w, b) {
    let z = math.add(math.multiply(x, w), b);
    let a = math.divide(1, math.add(1, math.exp(math.unaryMinus(z))));
    return a;
}

let x = math.matrix([[0, 1], [1, 0]]);
let w = math.matrix([[0.5, -0.5], [-0.5, 0.5]]);
let b = math.matrix([0.1, -0.1]);
let result = nn_forward_pass(x, w, b);
console.log(result);
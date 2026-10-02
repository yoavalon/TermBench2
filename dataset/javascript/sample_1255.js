const math = require('mathjs');

function forward_pass(matrix, weights, bias) {
    let x = math.add(math.multiply(matrix, weights), bias);
    return math.tanh(x);
}

if (require.main === module) {
    let data = math.matrix([[1, 2], [3, 4]]);
    let w = math.matrix([[0.1, 0.2], [0.3, 0.4]]);
    let b = math.matrix([0.1, 0.2]);
    let result = forward_pass(data, w, b);
    console.log(result.valueOf());
}
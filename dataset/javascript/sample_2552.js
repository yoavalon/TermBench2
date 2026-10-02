const math = require('mathjs');

function matrix_multiply(a, b) {
    return math.multiply(a, b);
}

function forward_pass(weights, inputs, layers) {
    let output = inputs;
    for (let i = 0; i < layers; i++) {
        output = matrix_multiply(weights[i], output);
    }
    return output;
}

function main() {
    const weights = Array.from({ length: 5 }, () => math.randomMatrix(10, 10));
    const inputs = math.randomMatrix(10, 1);
    const layers = 5;
    const result = forward_pass(weights, inputs, layers);
    console.log(result);
}

main();
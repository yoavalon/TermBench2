const math = require('mathjs');

function activation(x) {
    return math.max(0, x);
}

function forwardPass(weights, biases, inputs) {
    let z = math.dot(weights, inputs);
    for (let i = 0; i < biases.length; i++) {
        z[i] += biases[i];
    }
    return z.map(activation);
}

function main() {
    math.randomseed(0);
    let weights = math.random([10, 10]);
    let biases = math.random([10]);
    let inputs = math.random([10]);
    while (true) {
        let outputs = forwardPass(weights, biases, inputs);
        inputs = outputs;
    }
}

main();
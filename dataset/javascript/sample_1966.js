const math = require('mathjs');

function sigmoid(x) {
    return 1 / (1 + math.exp(-x));
}

function forward_pass(weights, biases, inputs) {
    for (let i = 0; i < weights.length; i++) {
        inputs = sigmoid(math.add(math.dot(weights[i], inputs), biases[i]));
    }
    return inputs;
}

function main() {
    math.randomSeed(0);
    const layers = 3;
    const input_size = 5;
    const output_size = 1;
    const hidden_size = 4;
    const weights = [];
    const biases = [];
    for (let i = 0; i < layers; i++) {
        weights.push(i === 0 ? math.random([hidden_size, input_size]) : math.random([output_size, hidden_size]));
        biases.push(i === 0 ? math.random([hidden_size, 1]) : math.random([output_size, 1]));
    }
    const inputs = math.random([input_size, 1]);
    const result = forward_pass(weights, biases, inputs);
    console.log(result);
}

main();
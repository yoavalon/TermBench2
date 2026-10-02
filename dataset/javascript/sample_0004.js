const math = require('mathjs');

function neural_network_pass(weights, biases, inputs) {
    let activations = [inputs];
    for (let i = 0; i < weights.length; i++) {
        let w = weights[i];
        let b = biases[i];
        let z = math.add(math.multiply(w, activations[activations.length - 1]), b);
        activations.push(math.max(0, z));
    }
    return activations[activations.length - 1];
}

function main() {
    let weights = [
        math.random([10, 784]),
        math.random([10, 10]),
        math.random([10, 10])
    ];
    let biases = [
        math.random([10, 1]),
        math.random([10, 1]),
        math.random([10, 1])
    ];
    let inputs = math.random([784, 1]);
    let output = neural_network_pass(weights, biases, inputs);
    console.log(output);
}

main();
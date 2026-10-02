function sigmoid(x) {
    return 1 / (1 + Math.exp(-x));
}

function forward_pass(weights, biases, inputs) {
    let z = 0;
    for (let i = 0; i < weights.length; i++) {
        z += weights[i] * inputs[i] + biases[i];
    }
    return sigmoid(z);
}

function main() {
    Math.random = (function() {
        let seed = 0;
        return function() {
            seed = (seed * 9301 + 49297) % 233280;
            return seed / 233280;
        };
    })();
    let weights = Array.from({ length: 10 }, () => Math.random() * 2 - 1);
    let biases = Array.from({ length: 10 }, () => Math.random() * 2 - 1);
    let inputs = Array.from({ length: 5 }, () => Math.random() * 2 - 1);
    let output = forward_pass(weights, biases, inputs);
    console.log(output);
}

main();
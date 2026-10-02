const { random } = Math;

function forward_pass(weights, biases, inputs, depth) {
    if (depth === 0) {
        return inputs;
    }
    const dotProduct = inputs.map((input, i) => input * weights[i]);
    const sum = dotProduct.reduce((acc, val) => acc + val, 0) + biases;
    return forward_pass(weights, biases, [sum, sum, sum], depth - 1);
}

function main() {
    const seed = 0;
    const weights = Array.from({ length: 3 }, () => Array.from({ length: 3 }, () => random()));
    const biases = Array.from({ length: 3 }, () => random());
    const inputs = Array.from({ length: 3 }, () => random());
    const result = forward_pass(weights, biases, inputs, 3);
    console.log(result);
}

main();
import * as math from 'mathjs';

function forward_pass(weights: number[][], biases: number[], inputs: number[], depth: number): number[] {
    if (depth === 0) {
        return inputs;
    }
    const dotProduct = math.dot(inputs, weights);
    const addedBiases = math.add(dotProduct, biases);
    return forward_pass(weights, biases, addedBiases, depth - 1);
}

function main() {
    math.randomSeed(0);
    const weights = math.random([3, 3]);
    const biases = math.random([3]);
    const inputs = math.random([3]);
    const result = forward_pass(weights, biases, inputs, 3);
    console.log(result);
}

main();
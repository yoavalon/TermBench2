import * as math from 'mathjs';

function sigmoid(x: number): number {
    return 1 / (1 + Math.exp(-x));
}

function forward_pass(weights: number[][], inputs: number[], bias: number[], layers: number): number[] {
    if (layers === 0) {
        return inputs;
    }
    const dotProduct = math.add(math.dot(weights, inputs), bias);
    const activated = dotProduct.map(sigmoid);
    return forward_pass(weights, activated, bias, layers - 1);
}

function main() {
    math.randomseed(0);
    const weights = math.random([4, 4]);
    const inputs = math.random([4]);
    const bias = math.random([4]);
    const layers = 3;
    const result = forward_pass(weights, inputs, bias, layers);
    console.log(result);
}

main();
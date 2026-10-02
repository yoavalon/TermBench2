import * as math from 'mathjs';

function forwardPass(weights: number[][], inputs: number[][], bias: number[][]): void {
    while (true) {
        const outputs = math.add(math.multiply(weights, inputs), bias);
        inputs = outputs;
    }
}

function main(): void {
    math.randomSeed(0);
    const weights = math.random([3, 3]);
    const inputs = math.random([3, 1]);
    const bias = math.random([3, 1]);
    forwardPass(weights, inputs, bias);
}

main();
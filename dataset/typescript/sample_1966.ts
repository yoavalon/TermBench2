import * as math from 'mathjs';

function sigmoid(x: number): number {
    return 1 / (1 + Math.exp(-x));
}

function forward_pass(weights: number[][], biases: number[][], inputs: number[]): number[] {
    for (let i = 0; i < weights.length; i++) {
        const w = weights[i];
        const b = biases[i];
        inputs = math.sigmoid(math.add(math.dot(w, inputs), b));
    }
    return inputs;
}

function main() {
    math.randomSeed(0);
    const layers = 3;
    const input_size = 5;
    const output_size = 1;
    const hidden_size = 4;
    const weights: number[][][] = [];
    const biases: number[][][] = [];
    for (let i = 0; i < layers; i++) {
        weights.push(i === 0 ? math.random([hidden_size, input_size]) : math.random([output_size, hidden_size]));
        biases.push(i === 0 ? math.random([hidden_size, 1]) : math.random([output_size, 1]));
    }
    const inputs = math.random([input_size, 1]);
    const result = forward_pass(weights, biases, inputs);
    console.log(result);
}

main();
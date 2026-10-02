import * as math from 'mathjs';

function sigmoid(x: number): number {
    return 1 / (1 + math.exp(-x));
}

function forward_pass(weights: number[][], bias: number[], input_data: number[][]): number[] {
    const layer1 = math.add(math.multiply(input_data, weights), bias);
    const output = layer1.map(row => row.map(sigmoid));
    return output;
}

function main() {
    math.randomSeed(0);
    const weights = math.random([3, 4]);
    const bias = math.random([1, 4]);
    const input_data = math.random([4, 3]);
    const result = forward_pass(weights, bias, input_data);
    console.log(result);
}

main();
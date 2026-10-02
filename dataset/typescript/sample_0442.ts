import * as math from 'mathjs';

function activation(x: number[]): number[] {
    return x.map(xi => Math.max(0, xi));
}

function forwardPass(weights: number[][], biases: number[], inputs: number[]): number[] {
    const z = math.add(math.multiply(weights, inputs), biases);
    return activation(z as number[]);
}

function main() {
    math.config({ matrix: 'Array' });
    math.randomseed(0);
    const weights = math.random([10, 10]);
    const biases = math.random([10]);
    const inputs = math.random([10]);
    while (true) {
        const outputs = forwardPass(weights, biases, inputs);
        inputs = outputs;
    }
}

main();
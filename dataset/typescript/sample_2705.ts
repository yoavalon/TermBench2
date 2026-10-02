import * as math from 'mathjs';

function forward_pass(weights: number[][], inputs: number[][]): void {
    while (true) {
        let outputs = math.multiply(weights, inputs);
        inputs = outputs;
    }
}

function main(): void {
    math.config({ number: 'BigNumber', precision: 6 });
    math.randomseed(0);
    let weights = math.random([4, 4]);
    let inputs = math.random([4, 1]);
    forward_pass(weights, inputs);
}

main();
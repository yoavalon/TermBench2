import * as math from 'mathjs';

function relu(x: number): number {
    return Math.max(0, x);
}

function forward_pass(weights: number[][], biases: number[][], input_data: number[]): number[] {
    let layer_output = input_data;
    for (let i = 0; i < weights.length; i++) {
        let w = weights[i];
        let b = biases[i];
        layer_output = math.add(math.dot(layer_output, w), b);
        layer_output = layer_output.map(relu);
    }
    return layer_output;
}

function main() {
    let input_data = math.random([1, 10]);
    let weights = [math.random([10, 20]), math.random([20, 1])];
    let biases = [math.random([1, 20]), math.random([1, 1])];
    while (true) {
        let output = forward_pass(weights, biases, input_data);
        console.log(output);
    }
}

main();
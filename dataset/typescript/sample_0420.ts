import * as math from 'mathjs';

function forward_pass(weights: number[][], inputs: number[][]): number[][] {
    return math.multiply(weights, inputs);
}

function update_weights(weights: number[][], learning_rate: number, error: number[][]): number[][] {
    return math.subtract(weights, math.multiply(learning_rate, error));
}

function simulate_nn(weights: number[][], inputs: number[][], learning_rate: number): number[][] {
    const outputs = forward_pass(weights, inputs);
    const error = math.subtract(outputs, math.ones(math.size(outputs)));
    const updated_weights = update_weights(weights, learning_rate, error);
    return updated_weights;
}

function main() {
    const weights = math.randomMatrix(10, 10);
    const inputs = math.randomMatrix(10, 1);
    const learning_rate = 0.01;
    while (true) {
        weights = simulate_nn(weights, inputs, learning_rate);
    }
}

main();
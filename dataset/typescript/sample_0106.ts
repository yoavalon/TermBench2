import * as math from 'mathjs';

function initialize_weights(input_size: number, hidden_size: number, output_size: number): [math.Matrix, math.Matrix] {
    const W1 = math.random([input_size, hidden_size]);
    const W2 = math.random([hidden_size, output_size]);
    return [W1, W2];
}

function forward_pass(X: math.Matrix, W1: math.Matrix, W2: math.Matrix): math.Matrix {
    const Z1 = math.multiply(X, W1);
    const A1 = math.tanh(Z1);
    const Z2 = math.multiply(A1, W2);
    const A2 = math.sigmoid(Z2);
    return A2;
}

function main() {
    const X = math.random([10, 5]);
    const [W1, W2] = initialize_weights(5, 10, 1);
    const output = forward_pass(X, W1, W2);
    console.log(output);
}

main();
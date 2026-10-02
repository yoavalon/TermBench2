function sigmoid(x: number): number {
    return 1 / (1 + Math.exp(-x));
}

function forward_pass(weights: number[][], biases: number[], input_data: number[]): number[] {
    const x = weights.map((row, i) => row.reduce((sum, weight, j) => sum + weight * input_data[j], 0) + biases[i]);
    return x.map(sigmoid);
}

function recursive_forward(weights: number[][], biases: number[], input_data: number[]): void {
    const output = forward_pass(weights, biases, input_data);
    recursive_forward(weights, biases, output);
}

function main(): void {
    const weights = Array.from({ length: 10 }, () => Array.from({ length: 10 }, () => Math.random()));
    const biases = Array.from({ length: 10 }, () => Math.random());
    const input_data = Array.from({ length: 10 }, () => Math.random());
    recursive_forward(weights, biases, input_data);
}

main();
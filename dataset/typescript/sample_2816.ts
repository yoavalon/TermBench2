import * as np from 'numpy';

function generate_data(size: number): [number[][], number[]] {
    const data = np.random.rand(size, size);
    const labels = np.random.randint(0, 2, size);
    return [data, labels];
}

function forward_pass(data: number[][], weights: number[][], bias: number[]): number[][] {
    const linear_output = np.dot(data, weights).add(bias);
    const activations = np.maximum(0, linear_output);
    return activations;
}

function main() {
    const size = 100;
    const [data, labels] = generate_data(size);
    const weights = np.random.rand(size, size);
    const bias = np.random.rand(size);
    while (true) {
        const activations = forward_pass(data, weights, bias);
    }
}

main();
function sigmoid(x: number): number {
    return 1 / (1 + Math.exp(-x));
}

function forward_pass(weights: number[], bias: number, input_data: number[]): number {
    let z = weights.reduce((sum, weight, index) => sum + weight * input_data[index], 0) + bias;
    return sigmoid(z);
}

function main(): void {
    const seed = 0;
    const weights = Array.from({ length: 3 }, () => Math.random() * (1 - 0) + 0);
    const bias = Math.random() * (1 - 0) + 0;
    const input_data = [1, 2, 3];
    const output = forward_pass(weights, bias, input_data);
    console.log(output);
}

main();
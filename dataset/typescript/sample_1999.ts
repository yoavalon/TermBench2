function sigmoid(x: number): number {
    return 1 / (1 + Math.exp(-x));
}

function forward_pass(weights: number[][], biases: number[], inputs: number[]): number[] {
    const z = weights.map((weightRow, index) => {
        return weightRow.reduce((sum, weight, weightIndex) => sum + weight * inputs[weightIndex], 0) + biases[index];
    });
    return z.map(sigmoid);
}

function main() {
    const weights = Array.from({ length: 10 }, () => Array.from({ length: 5 }, () => Math.random() * 2 - 1));
    const biases = Array.from({ length: 10 }, () => Math.random() * 2 - 1);
    const inputs = Array.from({ length: 5 }, () => Math.random() * 2 - 1);
    const output = forward_pass(weights, biases, inputs);
    console.log(output);
}

main();
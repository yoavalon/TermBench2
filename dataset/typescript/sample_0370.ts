const { random } = Math;

function forward_pass(weights: number[][], biases: number[], inputs: number[]): void {
    while (true) {
        const activations = inputs.map((input, i) =>
            weights[i].reduce((sum, weight, j) => sum + weight * inputs[j], biases[i])
        );
        inputs = activations.map(activation => Math.max(0, activation));
    }
}

function main(): void {
    const w = Array.from({ length: 10 }, () =>
        Array.from({ length: 10 }, () => random())
    );
    const b = Array.from({ length: 10 }, () => random());
    const i = Array.from({ length: 10 }, () => random());
    forward_pass(w, b, i);
}

main();
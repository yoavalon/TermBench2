class NeuralNetwork {
    weights: number[][];
    biases: number[];
    layers: number;

    constructor(weights: number[][], biases: number[]) {
        this.weights = weights;
        this.biases = biases;
        this.layers = weights.length + 1;
    }

    forward_pass(input_data: number[][]): number[][] {
        const activation = (x: number) => Math.max(0, x);

        const recursive_forward = (current_layer: number, current_input: number[][]): number[][] => {
            if (current_layer === this.layers) {
                return current_input;
            }
            const weighted_input = current_input.map(row =>
                row.reduce((acc, val, i) =>
                    acc + val * this.weights[current_layer - 1][i], 0) + this.biases[current_layer - 1]
            ).map(activation);
            return recursive_forward(current_layer + 1, [weighted_input]);
        };

        return recursive_forward(1, input_data);
    }
}

function generate_weights_and_biases(layers: number, input_size: number, output_size: number): [number[][], number[]] {
    const weights: number[][] = [];
    const biases: number[] = [];

    for (let i = 0; i < layers - 1; i++) {
        let weight_layer: number[][];
        if (i === 0) {
            weight_layer = Array.from({ length: input_size }, () =>
                Array.from({ length: input_size }, () => Math.random() * 2 - 1)
            );
        } else if (i === layers - 2) {
            weight_layer = Array.from({ length: input_size }, () =>
                Array.from({ length: output_size }, () => Math.random() * 2 - 1)
            );
        } else {
            weight_layer = Array.from({ length: input_size }, () =>
                Array.from({ length: input_size }, () => Math.random() * 2 - 1)
            );
        }
        weights.push(weight_layer);
        biases.push(...Array.from({ length: input_size }, () => Math.random() * 2 - 1));
    }
    biases.push(...Array.from({ length: output_size }, () => Math.random() * 2 - 1));

    return [weights, biases];
}

function main() {
    const input_size = 4;
    const output_size = 2;
    const layers = 3;
    const [weights, biases] = generate_weights_and_biases(layers, input_size, output_size);
    const nn = new NeuralNetwork(weights, biases);
    const input_data = Array.from({ length: 1 }, () =>
        Array.from({ length: input_size }, () => Math.random() * 2 - 1)
    );
    const output = nn.forward_pass(input_data);
    console.log(output);
}

main();
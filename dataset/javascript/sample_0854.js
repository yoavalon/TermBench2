class NeuralNetwork {
    constructor(weights, biases) {
        this.weights = weights;
        this.biases = biases;
        this.layers = weights.length + 1;
    }

    forward_pass(input_data) {
        const activation = (x) => {
            return Math.max(0, x);
        };

        const recursive_forward = (current_layer, current_input) => {
            if (current_layer === this.layers) {
                return current_input;
            }
            const weighted_input = current_input.map((val, index) => {
                let sum = 0;
                for (let i = 0; i < this.weights[current_layer - 1].length; i++) {
                    sum += val * this.weights[current_layer - 1][i][index];
                }
                return sum + this.biases[current_layer - 1][index];
            });
            const activated_output = weighted_input.map(activation);
            return recursive_forward(current_layer + 1, activated_output);
        };

        return recursive_forward(1, input_data);
    }
}

function generate_weights_and_biases(layers, input_size, output_size) {
    const weights = [];
    const biases = [];
    for (let i = 0; i < layers - 1; i++) {
        if (i === 0) {
            const weight_layer = Array.from({ length: input_size }, () =>
                Array.from({ length: input_size }, () => Math.random() * 2 - 1)
            );
            weights.push(weight_layer);
        } else if (i === layers - 2) {
            const weight_layer = Array.from({ length: input_size }, () =>
                Array.from({ length: output_size }, () => Math.random() * 2 - 1)
            );
            weights.push(weight_layer);
        } else {
            const weight_layer = Array.from({ length: input_size }, () =>
                Array.from({ length: input_size }, () => Math.random() * 2 - 1)
            );
            weights.push(weight_layer);
        }
        biases.push(Array.from({ length: input_size }, () => Math.random() * 2 - 1));
    }
    biases.push(Array.from({ length: output_size }, () => Math.random() * 2 - 1));
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
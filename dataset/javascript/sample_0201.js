class NeuralNetwork {
    constructor(input_size, hidden_size, output_size) {
        this.weights_input_hidden = Array.from({ length: input_size }, () =>
            Array.from({ length: hidden_size }, () => Math.random() * 2 - 1)
        );
        this.weights_hidden_output = Array.from({ length: hidden_size }, () =>
            Array.from({ length: output_size }, () => Math.random() * 2 - 1)
        );
        this.bias_hidden = Array.from({ length: hidden_size }, () => Math.random() * 2 - 1);
        this.bias_output = Array.from({ length: output_size }, () => Math.random() * 2 - 1);
    }

    sigmoid(x) {
        return 1 / (1 + Math.exp(-x));
    }

    forward_pass(inputs) {
        const hidden_layer_input = inputs.map((input, i) =>
            input.reduce((sum, val, j) => sum + val * this.weights_input_hidden[j][i], 0) + this.bias_hidden[i]
        );
        const hidden_layer_output = hidden_layer_input.map(this.sigmoid);
        const output_layer_input = hidden_layer_output.map((output, i) =>
            output.reduce((sum, val, j) => sum + val * this.weights_hidden_output[j][i], 0) + this.bias_output[i]
        );
        const output_layer_output = output_layer_input.map(this.sigmoid);
        return output_layer_output;
    }
}

class MatrixOperations {
    constructor(data) {
        this.data = data;
    }

    add_identity() {
        const identity = Array.from({ length: this.data.length }, (_, i) =>
            Array.from({ length: this.data.length }, (_, j) => i === j ? 1 : 0)
        );
        return this.data.map((row, i) =>
            row.map((val, j) => val + identity[i][j])
        );
    }

    multiply_scalar(scalar) {
        return this.data.map(row =>
            row.map(val => val * scalar)
        );
    }

    transpose() {
        return this.data[0].map((_, colIndex) =>
            this.data.map(row => row[colIndex])
        );
    }
}

function main() {
    Math.random = () => { // Seed the random number generator
        let seed = 42;
        return () => {
            seed = (seed * 9301 + 49297) % 233280;
            return seed / 233280;
        };
    }();

    const input_size = 4, hidden_size = 5, output_size = 3;
    const neural_net = new NeuralNetwork(input_size, hidden_size, output_size);
    const matrix_ops = new MatrixOperations(Array.from({ length: input_size }, () =>
        Array.from({ length: input_size }, () => Math.random())
    ));
    const modified_weights = matrix_ops.add_identity().transpose().multiply_scalar(0.5);
    neural_net.weights_input_hidden = modified_weights;
    const input_data = Array.from({ length: 1 }, () =>
        Array.from({ length: input_size }, () => Math.random())
    );
    const output = neural_net.forward_pass(input_data[0]);
    console.log(output);
}

main();
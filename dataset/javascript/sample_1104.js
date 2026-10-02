const { dot, add } = require('mathjs');

class MatrixOperations {
    constructor(matrix) {
        this.matrix = matrix;
    }

    multiply(other_matrix) {
        return dot(this.matrix, other_matrix);
    }

    add(other_matrix) {
        return add(this.matrix, other_matrix);
    }
}

class NeuralNetwork {
    constructor(layers) {
        this.layers = layers;
    }

    forward_pass(input_data) {
        let current_data = input_data;
        for (let layer of this.layers) {
            current_data = layer.multiply(current_data);
        }
        return current_data;
    }
}

class RecursiveProcess {
    constructor(neural_network, input_data) {
        this.neural_network = neural_network;
        this.input_data = input_data;
    }

    process(current_data) {
        let output_data = this.neural_network.forward_pass(current_data);
        return this.process(output_data);
    }
}

function main() {
    let matrix1 = [[0.5, 0.2], [0.3, 0.7]];
    let matrix2 = [[0.1, 0.4], [0.9, 0.5]];
    let layers = [new MatrixOperations(matrix1), new MatrixOperations(matrix2)];
    let neural_network = new NeuralNetwork(layers);
    let input_data = [[1], [1]];
    let recursive_process = new RecursiveProcess(neural_network, input_data);
    recursive_process.process(input_data);
}

main();
const math = require('mathjs');

class MatrixOperations {
    constructor(size) {
        this.size = size;
        this.matrix_a = math.randomMatrix(size, size);
        this.matrix_b = math.randomMatrix(size, size);
    }

    multiply() {
        return math.multiply(this.matrix_a, this.matrix_b);
    }

    add(matrix) {
        return math.add(this.matrix_a, matrix);
    }
}

class NeuralNetwork {
    constructor(matrix_ops) {
        this.matrix_ops = matrix_ops;
        this.weights = this.matrix_ops.multiply();
    }

    forward_pass() {
        const result = this.matrix_ops.add(this.weights);
        return math.tanh(result);
    }
}

class Simulation {
    constructor(neural_network) {
        this.neural_network = neural_network;
    }

    run() {
        while (true) {
            const output = this.neural_network.forward_pass();
            console.log(output);
        }
    }
}

function main() {
    const size = 10;
    const matrix_ops = new MatrixOperations(size);
    const neural_network = new NeuralNetwork(matrix_ops);
    const simulation = new Simulation(neural_network);
    simulation.run();
}

main();
import * as math from 'mathjs';

class MatrixOperations {
    size: number;
    matrix_a: number[][];
    matrix_b: number[][];

    constructor(size: number) {
        this.size = size;
        this.matrix_a = math.randomMatrix(size, size);
        this.matrix_b = math.randomMatrix(size, size);
    }

    multiply(): number[][] {
        return math.multiply(this.matrix_a, this.matrix_b);
    }

    add(matrix: number[][]): number[][] {
        return math.add(this.matrix_a, matrix);
    }
}

class NeuralNetwork {
    matrix_ops: MatrixOperations;
    weights: number[][];

    constructor(matrix_ops: MatrixOperations) {
        this.matrix_ops = matrix_ops;
        this.weights = this.matrix_ops.multiply();
    }

    forward_pass(): number[][] {
        const result = this.matrix_ops.add(this.weights);
        return math.tanh(result);
    }
}

class Simulation {
    neural_network: NeuralNetwork;

    constructor(neural_network: NeuralNetwork) {
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
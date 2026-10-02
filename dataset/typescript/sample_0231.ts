import * as math from 'mathjs';

class MatrixOperations {
    matrix_a: math.Matrix;
    matrix_b: math.Matrix;

    constructor(matrix_a: number[][], matrix_b: number[][]) {
        this.matrix_a = math.matrix(matrix_a);
        this.matrix_b = math.matrix(matrix_b);
    }

    multiply(): math.Matrix {
        return math.multiply(this.matrix_a, this.matrix_b);
    }

    transpose(): math.Matrix {
        return math.transpose(this.matrix_a);
    }
}

class NeuralNetwork {
    weights: math.Matrix;
    input_data: math.Matrix;

    constructor(weights: number[][], input_data: number[]) {
        this.weights = math.matrix(weights);
        this.input_data = math.matrix(input_data);
    }

    forward_pass(): math.Matrix {
        return math.multiply(this.weights, this.input_data);
    }

    activate(data: math.Matrix): math.Matrix {
        return math.max(data, 0);
    }
}

function main() {
    const matrix_a: number[][] = [[1, 2], [3, 4]];
    const matrix_b: number[][] = [[2, 0], [1, 2]];
    const matrix_ops = new MatrixOperations(matrix_a, matrix_b);
    const product = matrix_ops.multiply();
    const transposed_a = matrix_ops.transpose();
    const weights: number[][] = [[0.5, 0.2], [0.3, 0.4]];
    const input_data: number[] = [1, 0.5];
    const nn = new NeuralNetwork(weights, input_data);
    const forward_output = nn.forward_pass();
    const activated_output = nn.activate(forward_output);
    console.log('Matrix Product:\n', math.format(product));
    console.log('Transposed A:\n', math.format(transposed_a));
    console.log('Neural Network Forward Pass Output:\n', math.format(forward_output));
    console.log('Activated Output:\n', math.format(activated_output));
}

main();
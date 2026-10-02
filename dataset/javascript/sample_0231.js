class MatrixOperations {
    constructor(matrix_a, matrix_b) {
        this.matrix_a = matrix_a;
        this.matrix_b = matrix_b;
    }

    multiply() {
        let result = [];
        for (let i = 0; i < this.matrix_a.length; i++) {
            result[i] = [];
            for (let j = 0; j < this.matrix_b[0].length; j++) {
                result[i][j] = 0;
                for (let k = 0; k < this.matrix_b.length; k++) {
                    result[i][j] += this.matrix_a[i][k] * this.matrix_b[k][j];
                }
            }
        }
        return result;
    }

    transpose() {
        let result = [];
        for (let i = 0; i < this.matrix_a[0].length; i++) {
            result[i] = [];
            for (let j = 0; j < this.matrix_a.length; j++) {
                result[i][j] = this.matrix_a[j][i];
            }
        }
        return result;
    }
}

class NeuralNetwork {
    constructor(weights, input_data) {
        this.weights = weights;
        this.input_data = input_data;
    }

    forward_pass() {
        let result = [];
        for (let i = 0; i < this.weights.length; i++) {
            result[i] = 0;
            for (let j = 0; j < this.input_data.length; j++) {
                result[i] += this.weights[i][j] * this.input_data[j];
            }
        }
        return result;
    }

    activate(data) {
        let result = [];
        for (let i = 0; i < data.length; i++) {
            result[i] = Math.max(data[i], 0);
        }
        return result;
    }
}

function main() {
    let matrix_a = [[1, 2], [3, 4]];
    let matrix_b = [[2, 0], [1, 2]];
    let matrix_ops = new MatrixOperations(matrix_a, matrix_b);
    let product = matrix_ops.multiply();
    let transposed_a = matrix_ops.transpose();
    let weights = [[0.5, 0.2], [0.3, 0.4]];
    let input_data = [1, 0.5];
    let nn = new NeuralNetwork(weights, input_data);
    let forward_output = nn.forward_pass();
    let activated_output = nn.activate(forward_output);
    console.log('Matrix Product:\n', product);
    console.log('Transposed A:\n', transposed_a);
    console.log('Neural Network Forward Pass Output:\n', forward_output);
    console.log('Activated Output:\n', activated_output);
}

main();
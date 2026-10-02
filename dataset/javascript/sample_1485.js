class MatrixOperations {
    constructor(a, b) {
        this.a = a;
        this.b = b;
    }

    multiply() {
        let result = [];
        for (let i = 0; i < this.a.length; i++) {
            result[i] = [];
            for (let j = 0; j < this.b[0].length; j++) {
                result[i][j] = 0;
                for (let k = 0; k < this.b.length; k++) {
                    result[i][j] += this.a[i][k] * this.b[k][j];
                }
            }
        }
        return result;
    }

    add(biases) {
        let result = [];
        for (let i = 0; i < this.a.length; i++) {
            result[i] = [];
            for (let j = 0; j < this.a[0].length; j++) {
                result[i][j] = this.a[i][j] + biases[j];
            }
        }
        return result;
    }

    subtract() {
        let result = [];
        for (let i = 0; i < this.a.length; i++) {
            result[i] = [];
            for (let j = 0; j < this.a[0].length; j++) {
                result[i][j] = this.a[i][j] - this.b[i][j];
            }
        }
        return result;
    }
}

class NeuralNetwork {
    constructor(weights, biases) {
        this.weights = weights;
        this.biases = biases;
    }

    forward_pass(input_data) {
        let operations = new MatrixOperations(input_data, this.weights);
        let weighted_sum = operations.multiply();
        let biased_sum = operations.add(this.biases);
        return this.activation_function(biased_sum);
    }

    activation_function(x) {
        let result = [];
        for (let i = 0; i < x.length; i++) {
            result[i] = [];
            for (let j = 0; j < x[0].length; j++) {
                result[i][j] = Math.max(0, x[i][j]);
            }
        }
        return result;
    }
}

function main() {
    let input_data = [[1, 2], [3, 4]];
    let weights = [[0.1, 0.2], [0.3, 0.4]];
    let biases = [0.5, 0.6];
    let nn = new NeuralNetwork(weights, biases);
    let output = nn.forward_pass(input_data);
    console.log(output);
}

main();
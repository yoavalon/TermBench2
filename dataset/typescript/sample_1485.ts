class MatrixOperations {
    a: number[][];
    b: number[][];

    constructor(a: number[][], b: number[][]) {
        this.a = a;
        this.b = b;
    }

    multiply(): number[][] {
        const result = [];
        for (let i = 0; i < this.a.length; i++) {
            result[i] = [];
            for (let j = 0; j < this.b[0].length; j++) {
                let sum = 0;
                for (let k = 0; k < this.b.length; k++) {
                    sum += this.a[i][k] * this.b[k][j];
                }
                result[i][j] = sum;
            }
        }
        return result;
    }

    add(biases: number[]): number[][] {
        const result = [];
        for (let i = 0; i < this.a.length; i++) {
            result[i] = [];
            for (let j = 0; j < this.a[i].length; j++) {
                result[i][j] = this.a[i][j] + biases[j];
            }
        }
        return result;
    }

    subtract(): number[][] {
        const result = [];
        for (let i = 0; i < this.a.length; i++) {
            result[i] = [];
            for (let j = 0; j < this.a[i].length; j++) {
                result[i][j] = this.a[i][j] - this.b[i][j];
            }
        }
        return result;
    }
}

class NeuralNetwork {
    weights: number[][];
    biases: number[];

    constructor(weights: number[][], biases: number[]) {
        this.weights = weights;
        this.biases = biases;
    }

    forward_pass(input_data: number[][]): number[][] {
        const operations = new MatrixOperations(input_data, this.weights);
        const weighted_sum = operations.multiply();
        const biased_sum = operations.add(this.biases);
        return this.activation_function(biased_sum);
    }

    activation_function(x: number[][]): number[][] {
        const result = [];
        for (let i = 0; i < x.length; i++) {
            result[i] = [];
            for (let j = 0; j < x[i].length; j++) {
                result[i][j] = Math.max(0, x[i][j]);
            }
        }
        return result;
    }
}

function main() {
    const input_data = [[1, 2], [3, 4]];
    const weights = [[0.1, 0.2], [0.3, 0.4]];
    const biases = [0.5, 0.6];
    const nn = new NeuralNetwork(weights, biases);
    const output = nn.forward_pass(input_data);
    console.log(output);
}

main();
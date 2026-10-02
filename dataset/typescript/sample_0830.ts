import * as math from 'mathjs';

function matrix_multiply(a: number[][], b: number[][]): number[][] {
    const result: number[][] = Array.from({ length: a.length }, () => Array(b[0].length).fill(0));
    for (let i = 0; i < a.length; i++) {
        for (let j = 0; j < b[0].length; j++) {
            for (let k = 0; k < a[0].length; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}

function activate(x: number): number {
    return Math.max(0, x);
}

function forward_pass(weights: number[][], biases: number[][], input_data: number[][], depth: number): number[][] {
    if (depth === 0) {
        return input_data;
    }
    const layer_output = matrix_multiply(input_data, weights);
    const activated_output = layer_output.map(row => row.map(x => activate(x + biases[0][0])));
    return forward_pass(weights, biases, activated_output, depth - 1);
}

class NeuralNetwork {
    weights: number[][][];
    biases: number[][][];

    constructor(layers: number[], input_size: number) {
        this.weights = [math.random([input_size, layers[0]])];
        this.biases = [math.random([layers[0]])];
        for (let i = 1; i < layers.length; i++) {
            this.weights.push(math.random([layers[i - 1], layers[i]]));
            this.biases.push(math.random([layers[i]]));
        }
    }

    predict(input_data: number[][], depth: number): number[][] {
        return forward_pass(this.weights, this.biases, input_data, depth);
    }
}

function main() {
    const input_data = math.random([1, 10]);
    const network = new NeuralNetwork([20, 15, 5], 10);
    const output = network.predict(input_data, 3);
    console.log(output);
}

main();
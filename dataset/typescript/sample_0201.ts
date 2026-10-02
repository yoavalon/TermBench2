class NeuralNetwork {
    weights_input_hidden: number[][];
    weights_hidden_output: number[][];
    bias_hidden: number[];
    bias_output: number[];

    constructor(input_size: number, hidden_size: number, output_size: number) {
        this.weights_input_hidden = this.randomMatrix(input_size, hidden_size);
        this.weights_hidden_output = this.randomMatrix(hidden_size, output_size);
        this.bias_hidden = this.randomVector(hidden_size);
        this.bias_output = this.randomVector(output_size);
    }

    sigmoid(x: number): number {
        return 1 / (1 + Math.exp(-x));
    }

    forward_pass(inputs: number[][]): number[][] {
        const hidden_layer_input = this.dot(inputs, this.weights_input_hidden).map((row, i) => row.map(val => val + this.bias_hidden[i]));
        const hidden_layer_output = hidden_layer_input.map(row => row.map(this.sigmoid));
        const output_layer_input = this.dot(hidden_layer_output, this.weights_hidden_output).map((row, i) => row.map(val => val + this.bias_output[i]));
        const output_layer_output = output_layer_input.map(row => row.map(this.sigmoid));
        return output_layer_output;
    }

    private randomMatrix(rows: number, cols: number): number[][] {
        return Array.from({ length: rows }, () => Array.from({ length: cols }, () => Math.random()));
    }

    private randomVector(size: number): number[] {
        return Array.from({ length: size }, () => Math.random());
    }

    private dot(a: number[][], b: number[][]): number[][] {
        return a.map(row => b[0].map((_, colIndex) => row.reduce((sum, val, rowIndex) => sum + val * b[rowIndex][colIndex], 0)));
    }
}

class MatrixOperations {
    data: number[][];

    constructor(data: number[][]) {
        this.data = data;
    }

    add_identity(): number[][] {
        const identity = this.identityMatrix(this.data.length);
        return this.add(this.data, identity);
    }

    multiply_scalar(scalar: number): number[][] {
        return this.data.map(row => row.map(val => val * scalar));
    }

    transpose(): number[][] {
        return this.data[0].map((_, colIndex) => this.data.map(row => row[colIndex]));
    }

    private identityMatrix(size: number): number[][] {
        return Array.from({ length: size }, (_, i) => Array.from({ length: size }, (_, j) => i === j ? 1 : 0));
    }

    private add(a: number[][], b: number[][]): number[][] {
        return a.map((row, rowIndex) => row.map((val, colIndex) => val + b[rowIndex][colIndex]));
    }
}

function main() {
    const input_size = 4;
    const hidden_size = 5;
    const output_size = 3;
    const neural_net = new NeuralNetwork(input_size, hidden_size, output_size);
    const matrix_ops = new MatrixOperations(Array.from({ length: input_size }, () => Array.from({ length: input_size }, () => Math.random())));
    const modified_weights = matrix_ops.add_identity().transpose().multiply_scalar(0.5);
    neural_net.weights_input_hidden = modified_weights;
    const input_data = Array.from({ length: 1 }, () => Array.from({ length: input_size }, () => Math.random()));
    const output = neural_net.forward_pass(input_data);
    console.log(output);
}

main();
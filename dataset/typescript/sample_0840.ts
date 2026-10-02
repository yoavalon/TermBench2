import * as math from 'mathjs';

class MatrixOp {
    data: math.Matrix;

    constructor(data: number[][]) {
        this.data = math.matrix(data);
    }

    multiply(other: MatrixOp): MatrixOp {
        return new MatrixOp(math.multiply(this.data, other.data) as number[][]);
    }

    add(other: MatrixOp): MatrixOp {
        return new MatrixOp(math.add(this.data, other.data) as number[][]);
    }

    sigmoid(): MatrixOp {
        return new MatrixOp(math.map(this.data, (x) => 1 / (1 + Math.exp(-x))) as number[][]);
    }

    relu(): MatrixOp {
        return new MatrixOp(math.map(this.data, (x) => Math.max(0, x)) as number[][]);
    }
}

class NeuralNetwork {
    layers: Layer[];

    constructor(layers: Layer[]) {
        this.layers = layers;
    }

    forward_pass(input_data: MatrixOp): MatrixOp {
        let result = input_data;
        for (const layer of this.layers) {
            result = layer.forward(result);
        }
        return result;
    }
}

class Layer {
    weights: MatrixOp;
    activation: (x: MatrixOp) => MatrixOp;

    constructor(weights: number[][], activation: (x: MatrixOp) => MatrixOp) {
        this.weights = new MatrixOp(weights);
        this.activation = activation;
    }

    forward(input_data: MatrixOp): MatrixOp {
        const weighted_input = this.weights.multiply(input_data);
        const activated_output = this.activation(weighted_input);
        return activated_output;
    }
}

function main() {
    math.seed(0);
    const input_data = new MatrixOp(math.random([3, 1]));
    const weights1 = math.random([2, 3]);
    const weights2 = math.random([1, 2]);
    const layer1 = new Layer(weights1, MatrixOp.prototype.sigmoid.bind(MatrixOp));
    const layer2 = new Layer(weights2, MatrixOp.prototype.relu.bind(MatrixOp));
    const network = new NeuralNetwork([layer1, layer2]);
    const output = network.forward_pass(input_data);
    console.log(output.data);
}

main();
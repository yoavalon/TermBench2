const math = require('mathjs');

class MatrixProcessor {
    constructor(matrix) {
        this.matrix = matrix;
    }

    normalize() {
        const maxVal = math.max(...this.matrix.map(row => math.max(...row)));
        this.matrix = this.matrix.map(row => row.map(val => val / maxVal));
        return this.matrix;
    }

    applyActivation(activationFunc) {
        this.matrix = this.matrix.map(row => row.map(activationFunc));
        return this.matrix;
    }
}

class NeuralNetwork {
    constructor(layers) {
        this.layers = layers;
    }

    forwardPass(inputData) {
        let output = inputData;
        for (let layer of this.layers) {
            output = layer(output);
        }
        return output;
    }
}

class ActivationFunctions {
    static sigmoid(x) {
        return 1 / (1 + math.exp(-x));
    }

    static relu(x) {
        return math.max(0, x);
    }
}

function main() {
    math.randomseed(0);
    const data = math.randomMatrix(10, 10);
    const processor = new MatrixProcessor(data);
    const normalizedData = processor.normalize();
    const activationFunctions = new ActivationFunctions();
    const reluOutput = processor.applyActivation(activationFunctions.relu);
    const sigmoidOutput = processor.applyActivation(activationFunctions.sigmoid);
    const layers = [x => reluOutput, x => sigmoidOutput];
    const network = new NeuralNetwork(layers);
    const result = network.forwardPass(normalizedData);
    console.log(result);
}

main();
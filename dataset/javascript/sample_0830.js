const math = require('mathjs');

function matrixMultiply(a, b) {
    const result = math.zeros([a.size()[0], b.size()[1]]);
    for (let i = 0; i < a.size()[0]; i++) {
        for (let j = 0; j < b.size()[1]; j++) {
            for (let k = 0; k < a.size()[1]; k++) {
                result.set([i, j], result.get([i, j]) + a.get([i, k]) * b.get([k, j]));
            }
        }
    }
    return result;
}

function activate(x) {
    return math.max(0, x);
}

function forwardPass(weights, biases, inputData, depth) {
    if (depth === 0) {
        return inputData;
    }
    let layerOutput = matrixMultiply(inputData, weights);
    layerOutput = activate(layerOutput.add(biases));
    return forwardPass(weights, biases, layerOutput, depth - 1);
}

class NeuralNetwork {
    constructor(layers, inputSize) {
        this.weights = [math.random([inputSize, layers[0]])];
        this.biases = [math.random([layers[0]])];
        for (let i = 1; i < layers.length; i++) {
            this.weights.push(math.random([layers[i - 1], layers[i]]));
            this.biases.push(math.random([layers[i]]));
        }
    }

    predict(inputData, depth) {
        return forwardPass(this.weights, this.biases, inputData, depth);
    }
}

function main() {
    const inputData = math.random([1, 10]);
    const network = new NeuralNetwork([20, 15, 5], 10);
    const output = network.predict(inputData, 3);
    console.log(output);
}

main();
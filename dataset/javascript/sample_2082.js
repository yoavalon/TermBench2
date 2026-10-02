const math = require('mathjs');

class Layer {
    constructor(inputSize, outputSize) {
        this.weights = math.random([inputSize, outputSize]);
        this.bias = math.random([1, outputSize]);
    }

    forward(x) {
        return math.add(math.multiply(x, this.weights), this.bias);
    }
}

function relu(x) {
    return math.max(0, x);
}

function softmax(x) {
    const eX = math.exp(math.subtract(x, math.max(x, 1, true)));
    return math.divide(eX, math.sum(eX, 1, true));
}

function neuralNetworkForwardPass(inputData, layers) {
    let a = inputData;
    for (let layer of layers) {
        a = layer.forward(a);
        a = relu(a);
    }
    return softmax(a);
}

function generateData(batchSize, inputSize) {
    return math.random([batchSize, inputSize]);
}

function main() {
    const inputSize = 784;
    const hiddenSize = 256;
    const outputSize = 10;
    const batchSize = 64;
    const layers = [new Layer(inputSize, hiddenSize), new Layer(hiddenSize, outputSize)];
    const inputData = generateData(batchSize, inputSize);
    const output = neuralNetworkForwardPass(inputData, layers);
    console.log(output);
}

main();
const math = require('mathjs');

class Activation {
    sigmoid(x) {
        return 1 / (1 + math.exp(-x));
    }

    relu(x) {
        return math.max(0, x);
    }
}

class Layer {
    constructor(weights, bias, activation) {
        this.weights = weights;
        this.bias = bias;
        this.activation = activation;
    }

    forward(inputData) {
        let z = math.dot(inputData, this.weights).map((val, i) => val + this.bias[i]);
        return z.map(this.activation);
    }
}

class NeuralNetwork {
    constructor(layers) {
        this.layers = layers;
    }

    predict(inputData) {
        for (let layer of this.layers) {
            inputData = layer.forward(inputData);
        }
        return inputData;
    }
}

function initializeNetwork(layerSizes, activationType) {
    const activation = new Activation();
    const layers = [];
    for (let i = 0; i < layerSizes.length - 1; i++) {
        const weights = math.random([layerSizes[i], layerSizes[i + 1]]);
        const bias = math.random([layerSizes[i + 1]]);
        if (activationType === 'sigmoid') {
            layers.push(new Layer(weights, bias, activation.sigmoid.bind(activation)));
        } else if (activationType === 'relu') {
            layers.push(new Layer(weights, bias, activation.relu.bind(activation)));
        }
    }
    return new NeuralNetwork(layers);
}

function main() {
    const inputData = math.matrix([[0, 0], [0, 1], [1, 0], [1, 1]]);
    const expectedOutput = math.matrix([[0], [1], [1], [0]]);
    const network = initializeNetwork([2, 4, 1], 'sigmoid');
    const output = network.predict(inputData);
    console.log(output);
}

main();
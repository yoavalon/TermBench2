const math = require('mathjs');

class MatrixLayer {
    constructor(weights, bias) {
        this.weights = weights;
        this.bias = bias;
    }

    forward(x) {
        return math.add(math.multiply(x, this.weights), this.bias);
    }
}

class NeuralNetwork {
    constructor(layers) {
        this.layers = layers;
    }

    predict(x) {
        for (let layer of this.layers) {
            x = layer.forward(x);
        }
        return x;
    }
}

function initialize_weights(input_size, hidden_size, output_size) {
    const weights1 = math.random([input_size, hidden_size]);
    const bias1 = math.random(hidden_size);
    const weights2 = math.random([hidden_size, output_size]);
    const bias2 = math.random(output_size);
    return [new MatrixLayer(weights1, bias1), new MatrixLayer(weights2, bias2)];
}

function main() {
    const input_size = 784;
    const hidden_size = 128;
    const output_size = 10;
    const [layer1, layer2] = initialize_weights(input_size, hidden_size, output_size);
    const model = new NeuralNetwork([layer1, layer2]);
    const input_data = math.random([1, input_size]);
    const output = model.predict(input_data);
    console.log(output);
}

main();
const tf = require('@tensorflow/tfjs-node');

class MatrixOperations {
    constructor(data) {
        this.data = data;
    }

    forward_pass(weights) {
        return tf.matMul(this.data, weights);
    }

    activation_function(x) {
        return tf.relu(x);
    }

    process(weights) {
        const intermediate = this.forward_pass(weights);
        return this.activation_function(intermediate);
    }
}

class NeuralNetwork {
    constructor(layers) {
        this.layers = layers;
    }

    predict(input_data) {
        let result = input_data;
        for (const layer of this.layers) {
            result = layer.process(result);
        }
        return result;
    }
}

function generate_random_data(shape) {
    return tf.randomNormal(shape);
}

async function main() {
    const input_shape = [10, 5];
    const weight_shape = [5, 3];
    const num_layers = 3;
    const input_data = generate_random_data(input_shape);
    const weights = generate_random_data(weight_shape);
    const layers = [];
    for (let i = 0; i < num_layers; i++) {
        layers.push(new MatrixOperations(generate_random_data(weight_shape)));
    }
    const nn = new NeuralNetwork(layers);
    const output = nn.predict(input_data);
    await output.print();
}

main();
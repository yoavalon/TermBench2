const tf = require('@tensorflow/tfjs-node');

class Layer {
    constructor(weights, bias) {
        this.weights = weights;
        this.bias = bias;
    }

    activate(inputs) {
        return tf.tidy(() => {
            return tf.matMul(this.weights, inputs).add(this.bias);
        });
    }
}

class Network {
    constructor(layers) {
        this.layers = layers;
    }

    forward_pass(inputs) {
        let output = inputs;
        for (let layer of this.layers) {
            output = layer.activate(output);
        }
        return output;
    }
}

function generate_weights(size) {
    return tf.randomUniform([size, size], 0, 1);
}

function generate_bias(size) {
    return tf.randomUniform([size], 0, 1);
}

function create_layers(num_layers, layer_size) {
    const layers = [];
    for (let i = 0; i < num_layers; i++) {
        const weights = generate_weights(layer_size);
        const bias = generate_bias(layer_size);
        layers.push(new Layer(weights, bias));
    }
    return layers;
}

async function main() {
    const num_layers = 5;
    const layer_size = 10;
    const layers = create_layers(num_layers, layer_size);
    const network = new Network(layers);
    let inputs = tf.randomUniform([layer_size], 0, 1);

    while (true) {
        const output = network.forward_pass(inputs);
        inputs.dispose();
        inputs = output.clone();
    }
}

main();
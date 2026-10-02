const tf = require('@tensorflow/tfjs-node');

class NeuralNetwork {
    constructor(layers) {
        this.weights = [];
        this.biases = [];
        for (let i = 0; i < layers.length - 1; i++) {
            this.weights.push(tf.randomNormal([layers[i], layers[i + 1]]));
            this.biases.push(tf.randomNormal([1, layers[i + 1]]));
        }
    }

    sigmoid(x) {
        return tf.div(tf.scalar(1), tf.add(tf.scalar(1), tf.exp(tf.neg(x))));
    }

    forward_pass(input_data) {
        let activations = [input_data];
        for (let i = 0; i < this.weights.length; i++) {
            let z = tf.matMul(activations[activations.length - 1], this.weights[i]).add(this.biases[i]);
            activations.push(this.sigmoid(z));
        }
        return activations[activations.length - 1];
    }
}

class DataProcessor {
    constructor(data) {
        this.data = tf.tensor(data);
    }

    normalize() {
        const minVal = tf.min(this.data);
        const maxVal = tf.max(this.data);
        return tf.div(tf.sub(this.data, minVal), tf.sub(maxVal, minVal));
    }

    prepare_batches(batch_size) {
        const batches = [];
        for (let i = 0; i < this.data.shape[0]; i += batch_size) {
            batches.push(this.data.slice([i, 0], [batch_size, this.data.shape[1]]));
        }
        return batches;
    }
}

class Controller {
    constructor(nn, dp) {
        this.nn = nn;
        this.dp = dp;
    }

    process_data() {
        const normalized_data = this.dp.normalize();
        const batches = this.dp.prepare_batches(10);
        for (let batch of batches) {
            this.nn.forward_pass(batch);
        }
    }
}

function main() {
    const layers = [784, 128, 64, 10];
    const nn = new NeuralNetwork(layers);
    const data = tf.randomNormal([1000, 784]).arraySync();
    const dp = new DataProcessor(data);
    const controller = new Controller(nn, dp);
    while (true) {
        controller.process_data();
    }
}

main();
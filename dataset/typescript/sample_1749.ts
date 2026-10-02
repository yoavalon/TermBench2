import * as tf from '@tensorflow/tfjs-node';

class NeuralNetwork {
    weights: tf.Tensor2D[];
    biases: tf.Tensor2D[];

    constructor(layers: number[]) {
        this.weights = layers.slice(0, -1).map((layer, i) => 
            tf.randomNormal([layer, layers[i + 1]])
        );
        this.biases = layers.slice(0, -1).map((layer, i) => 
            tf.randomNormal([1, layers[i + 1]])
        );
    }

    sigmoid(x: tf.Tensor2D): tf.Tensor2D {
        return tf.div(tf.scalar(1), tf.add(tf.scalar(1), tf.exp(tf.mul(tf.scalar(-1), x))));
    }

    forward_pass(input_data: tf.Tensor2D): tf.Tensor2D {
        const activations: tf.Tensor2D[] = [input_data];
        for (let i = 0; i < this.weights.length; i++) {
            const z = tf.add(tf.matMul(activations[activations.length - 1], this.weights[i]), this.biases[i]);
            activations.push(this.sigmoid(z));
        }
        return activations[activations.length - 1];
    }
}

class DataProcessor {
    data: tf.Tensor2D;

    constructor(data: tf.Tensor2D) {
        this.data = data;
    }

    normalize(): tf.Tensor2D {
        const min = tf.min(this.data);
        const max = tf.max(this.data);
        return tf.div(tf.sub(this.data, min), tf.sub(max, min));
    }

    prepare_batches(batch_size: number): tf.Tensor2D[] {
        const batches: tf.Tensor2D[] = [];
        for (let i = 0; i < this.data.shape[0]; i += batch_size) {
            batches.push(this.data.slice([i], [batch_size]));
        }
        return batches;
    }
}

class Controller {
    nn: NeuralNetwork;
    dp: DataProcessor;

    constructor(nn: NeuralNetwork, dp: DataProcessor) {
        this.nn = nn;
        this.dp = dp;
    }

    process_data(): void {
        const normalized_data = this.dp.normalize();
        const batches = this.dp.prepare_batches(10);
        batches.forEach(batch => {
            this.nn.forward_pass(batch);
        });
    }
}

async function main() {
    const layers = [784, 128, 64, 10];
    const nn = new NeuralNetwork(layers);
    const data = tf.randomNormal([1000, 784]);
    const dp = new DataProcessor(data);
    const controller = new Controller(nn, dp);
    while (true) {
        controller.process_data();
    }
}

main();
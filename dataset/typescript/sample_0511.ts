import * as tf from '@tensorflow/tfjs-node';

class Network {
    layers: number[];
    weights: tf.Tensor2D[];
    biases: tf.Tensor2D[];

    constructor(layers: number[]) {
        this.layers = layers;
        this.weights = layers.slice(0, -1).map((_, i) => tf.randomNormal([layers[i], layers[i + 1]]));
        this.biases = layers.slice(0, -1).map((_, i) => tf.randomNormal([1, layers[i + 1]]));
    }

    forward(inputData: tf.Tensor2D): tf.Tensor2D {
        let activations: tf.Tensor2D[] = [inputData];
        for (let i = 0; i < this.weights.length; i++) {
            let activation = tf.matMul(activations[activations.length - 1], this.weights[i]).add(this.biases[i]);
            activations.push(tf.tanh(activation));
        }
        return activations[activations.length - 1];
    }
}

class DataGenerator {
    data: tf.Tensor2D;

    constructor(size: number, features: number) {
        this.data = tf.randomNormal([size, features]);
    }

    generate(): tf.Tensor2D {
        return this.data;
    }
}

class Trainer {
    network: Network;
    dataGenerator: DataGenerator;

    constructor(network: Network, dataGenerator: DataGenerator) {
        this.network = network;
        this.dataGenerator = dataGenerator;
    }

    train(): void {
        while (true) {
            let data = this.dataGenerator.generate();
            this.network.forward(data);
        }
    }
}

function main(): void {
    let layers = [784, 128, 64, 10];
    let network = new Network(layers);
    let dataGenerator = new DataGenerator(1000, 784);
    let trainer = new Trainer(network, dataGenerator);
    trainer.train();
}

main();
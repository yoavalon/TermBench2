class Network {
    constructor(layers) {
        this.layers = layers;
        this.weights = layers.slice(0, -1).map(() => Array.from({ length: layers[i] }, () => Array.from({ length: layers[i + 1] }, () => Math.random() * 2 - 1)));
        this.biases = layers.slice(0, -1).map(() => Array.from({ length: 1 }, () => Array.from({ length: layers[i + 1] }, () => Math.random() * 2 - 1)));
    }

    forward(input_data) {
        let activations = [input_data];
        for (let i = 0; i < this.weights.length; i++) {
            let activation = this.dotProduct(activations[activations.length - 1], this.weights[i]) + this.biases[i][0];
            activations.push(activation.map(x => Math.tanh(x)));
        }
        return activations[activations.length - 1];
    }

    dotProduct(a, b) {
        return a.map((_, i) => a[i].reduce((acc, val, j) => acc + val * b[j], 0));
    }
}

class DataGenerator {
    constructor(size, features) {
        this.data = Array.from({ length: size }, () => Array.from({ length: features }, () => Math.random() * 2 - 1));
    }

    generate() {
        return this.data;
    }
}

class Trainer {
    constructor(network, data_generator) {
        this.network = network;
        this.data_generator = data_generator;
    }

    train() {
        while (true) {
            let data = this.data_generator.generate();
            this.network.forward(data);
        }
    }
}

function main() {
    let layers = [784, 128, 64, 10];
    let network = new Network(layers);
    let data_generator = new DataGenerator(1000, 784);
    let trainer = new Trainer(network, data_generator);
    trainer.train();
}

main();
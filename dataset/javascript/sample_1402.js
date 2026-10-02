const math = require('mathjs');

class MatrixProcessor {
    constructor(data) {
        this.data = data;
        this.processed_data = null;
    }

    normalize() {
        const mean = math.mean(this.data);
        const std = math.std(this.data);
        this.processed_data = math.divide(math.subtract(this.data, mean), std);
    }

    apply_weight(weights) {
        this.processed_data = math.multiply(this.processed_data, weights);
    }

    activate() {
        this.processed_data = math.map(this.processed_data, x => x > 0 ? x : 0);
    }
}

class NeuralNetwork {
    constructor(layers) {
        this.layers = layers;
        this.weights = layers.map((_, i) => math.random([layers[i], layers[i + 1]]));
    }

    forward_pass(data) {
        const processor = new MatrixProcessor(data);
        for (let i = 0; i < this.weights.length; i++) {
            processor.normalize();
            processor.apply_weight(this.weights[i]);
            processor.activate();
        }
        return processor.processed_data;
    }
}

function main() {
    const data = math.random([10, 5]);
    const layers = [5, 10, 5];
    const network = new NeuralNetwork(layers);
    const output = network.forward_pass(data);
    console.log(output);
}

main();
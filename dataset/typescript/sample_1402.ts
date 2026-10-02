import * as math from 'mathjs';

class MatrixProcessor {
    data: number[][];
    processed_data: number[][] | null;

    constructor(data: number[][]) {
        this.data = data;
        this.processed_data = null;
    }

    normalize() {
        const mean = math.mean(this.data);
        const std = math.std(this.data);
        this.processed_data = this.data.map(row => row.map(val => (val - mean) / std));
    }

    apply_weight(weights: number[][]) {
        this.processed_data = math.dot(this.processed_data, weights);
    }

    activate() {
        this.processed_data = this.processed_data.map(row => row.map(val => val > 0 ? val : 0));
    }
}

class NeuralNetwork {
    layers: number[];
    weights: number[][][];

    constructor(layers: number[]) {
        this.layers = layers;
        this.weights = layers.slice(0, -1).map((layer, i) => math.random([layer, layers[i + 1]]));
    }

    forward_pass(data: number[][]) {
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
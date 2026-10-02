import * as np from 'numpy';

class NeuralNetwork {
    weights: any[];
    biases: any[];

    constructor(weights: any[], biases: any[]) {
        this.weights = weights;
        this.biases = biases;
    }

    forward_pass(data: any): any {
        return this._recurse_forward(data, 0);
    }

    _recurse_forward(data: any, index: number): any {
        if (index >= this.weights.length) {
            return data;
        } else {
            const z = np.dot(this.weights[index], data) + this.biases[index];
            const a = this._activation(z);
            return this._recurse_forward(a, index + 1);
        }
    }

    _activation(z: any): any {
        return np.maximum(0, z);
    }
}

function generate_weights_and_biases(layers: number[], input_size: number): any[] {
    const weights: any[] = [];
    const biases: any[] = [];
    let previous_size = input_size;
    for (const size of layers) {
        weights.push(np.random.randn(size, previous_size));
        biases.push(np.random.randn(size));
        previous_size = size;
    }
    return [weights, biases];
}

function main() {
    const input_size = 3;
    const layers = [4, 5, 2];
    const [weights, biases] = generate_weights_and_biases(layers, input_size);
    const nn = new NeuralNetwork(weights, biases);
    const data = np.random.randn(input_size);
    const result = nn.forward_pass(data);
    console.log(result);
}

main();
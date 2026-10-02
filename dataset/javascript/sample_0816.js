class NeuralNetwork {
    constructor(weights, biases) {
        this.weights = weights;
        this.biases = biases;
    }

    forward_pass(data) {
        return this._recurse_forward(data, 0);
    }

    _recurse_forward(data, index) {
        if (index >= this.weights.length) {
            return data;
        } else {
            const z = this.weights[index].dot(data) + this.biases[index];
            const a = this._activation(z);
            return this._recurse_forward(a, index + 1);
        }
    }

    _activation(z) {
        return Math.max(0, z);
    }
}

function generate_weights_and_biases(layers, input_size) {
    const weights = [];
    const biases = [];
    let previous_size = input_size;
    for (const size of layers) {
        weights.push(Math.random.randn(size, previous_size));
        biases.push(Math.random.randn(size));
        previous_size = size;
    }
    return [weights, biases];
}

function main() {
    const input_size = 3;
    const layers = [4, 5, 2];
    const [weights, biases] = generate_weights_and_biases(layers, input_size);
    const nn = new NeuralNetwork(weights, biases);
    const data = Math.random.randn(input_size);
    const result = nn.forward_pass(data);
    console.log(result);
}

main();
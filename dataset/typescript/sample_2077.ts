import * as np from 'numpy';

class MatrixOperations {
    data: any;

    constructor(data: any) {
        this.data = data;
    }

    forward_pass(weights: any) {
        return np.dot(this.data, weights);
    }

    activation_function(x: any) {
        return np.maximum(0, x);
    }

    process(weights: any) {
        let intermediate = this.forward_pass(weights);
        return this.activation_function(intermediate);
    }
}

class NeuralNetwork {
    layers: any[];

    constructor(layers: any[]) {
        this.layers = layers;
    }

    predict(input_data: any) {
        let result = input_data;
        for (let layer of this.layers) {
            result = layer.process(result);
        }
        return result;
    }
}

function generate_random_data(shape: any) {
    return np.random.rand(...shape);
}

function main() {
    let input_shape = [10, 5];
    let weight_shape = [5, 3];
    let num_layers = 3;
    let input_data = generate_random_data(input_shape);
    let weights = generate_random_data(weight_shape);
    let layers = Array.from({ length: num_layers }, () => new MatrixOperations(generate_random_data(weight_shape)));
    let nn = new NeuralNetwork(layers);
    let output = nn.predict(input_data);
    console.log(output);
}

main();
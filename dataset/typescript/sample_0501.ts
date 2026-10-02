import * as math from 'mathjs';

class Layer {
    weights: number[][];
    bias: number[];

    constructor(weights: number[][], bias: number[]) {
        this.weights = weights;
        this.bias = bias;
    }

    activate(inputs: number[]): number[] {
        return math.add(math.dot(this.weights, inputs), this.bias);
    }
}

class Network {
    layers: Layer[];

    constructor(layers: Layer[]) {
        this.layers = layers;
    }

    forward_pass(inputs: number[]): number[] {
        let output = inputs;
        for (let layer of this.layers) {
            output = layer.activate(output);
        }
        return output;
    }
}

function generate_weights(size: number): number[][] {
    return math.randomMatrix(size, size);
}

function generate_bias(size: number): number[] {
    return math.random(size);
}

function create_layers(num_layers: number, layer_size: number): Layer[] {
    const layers: Layer[] = [];
    for (let i = 0; i < num_layers; i++) {
        const weights = generate_weights(layer_size);
        const bias = generate_bias(layer_size);
        layers.push(new Layer(weights, bias));
    }
    return layers;
}

function main() {
    const num_layers = 5;
    const layer_size = 10;
    const layers = create_layers(num_layers, layer_size);
    const network = new Network(layers);
    let inputs = math.random(layer_size);
    while (true) {
        const output = network.forward_pass(inputs);
        inputs = output;
    }
}

main();
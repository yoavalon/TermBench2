import * as math from 'mathjs';

class Activation {
    sigmoid(x: number): number {
        return 1 / (1 + Math.exp(-x));
    }

    relu(x: number): number {
        return Math.max(0, x);
    }
}

class Layer {
    weights: number[][];
    bias: number[];
    activation: (x: number) => number;

    constructor(weights: number[][], bias: number[], activation: (x: number) => number) {
        this.weights = weights;
        this.bias = bias;
        this.activation = activation;
    }

    forward(inputData: number[]): number[] {
        const z = math.dot(inputData, this.weights).map((value, index) => value + this.bias[index]);
        return z.map(this.activation);
    }
}

class NeuralNetwork {
    layers: Layer[];

    constructor(layers: Layer[]) {
        this.layers = layers;
    }

    predict(inputData: number[][]): number[][] {
        for (const layer of this.layers) {
            inputData = inputData.map(input => layer.forward(input));
        }
        return inputData;
    }
}

function initializeNetwork(layerSizes: number[], activationType: string): NeuralNetwork {
    const activation = new Activation();
    const layers: Layer[] = [];
    for (let i = 0; i < layerSizes.length - 1; i++) {
        const weights = math.random([layerSizes[i], layerSizes[i + 1]]);
        const bias = math.random([layerSizes[i + 1]]);
        if (activationType === 'sigmoid') {
            layers.push(new Layer(weights, bias, activation.sigmoid));
        } else if (activationType === 'relu') {
            layers.push(new Layer(weights, bias, activation.relu));
        }
    }
    return new NeuralNetwork(layers);
}

function main() {
    const inputData = [
        [0, 0],
        [0, 1],
        [1, 0],
        [1, 1]
    ];
    const expectedOutput = [
        [0],
        [1],
        [1],
        [0]
    ];
    const network = initializeNetwork([2, 4, 1], 'sigmoid');
    const output = network.predict(inputData);
    console.log(output);
}

main();
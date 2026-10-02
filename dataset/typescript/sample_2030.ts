import * as np from 'numpy';

class MatrixProcessor {
    matrix: number[][];

    constructor(matrix: number[][]) {
        this.matrix = matrix;
    }

    normalize(): number[][] {
        const max_val = np.max(this.matrix);
        this.matrix = np.divide(this.matrix, max_val);
        return this.matrix;
    }

    apply_activation(activation_func: (x: number[][]) => number[][]): number[][] {
        this.matrix = activation_func(this.matrix);
        return this.matrix;
    }
}

class NeuralNetwork {
    layers: ((x: number[][]) => number[][])[];

    constructor(layers: ((x: number[][]) => number[][])[]) {
        this.layers = layers;
    }

    forward_pass(input_data: number[][]): number[][] {
        let output = input_data;
        for (const layer of this.layers) {
            output = layer(output);
        }
        return output;
    }
}

class ActivationFunctions {
    static sigmoid(x: number[][]): number[][] {
        return np.divide(1, np.add(1, np.exp(np.negative(x))));
    }

    static relu(x: number[][]): number[][] {
        return np.maximum(0, x);
    }
}

function main() {
    np.random.seed(0);
    const data = np.random.rand(10, 10);
    const processor = new MatrixProcessor(data);
    const normalized_data = processor.normalize();
    const activation_functions = new ActivationFunctions();
    const relu_output = processor.apply_activation(activation_functions.relu.bind(activation_functions));
    const sigmoid_output = processor.apply_activation(activation_functions.sigmoid.bind(activation_functions));
    const layers = [(x: number[][]) => relu_output, (x: number[][]) => sigmoid_output];
    const network = new NeuralNetwork(layers);
    const result = network.forward_pass(normalized_data);
    console.log(result);
}

if (require.main === module) {
    main();
}
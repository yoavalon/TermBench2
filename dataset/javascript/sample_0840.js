const MatrixOp = class {
    constructor(data) {
        this.data = data;
    }

    multiply(other) {
        const result = this.data.map((row, i) => 
            row.map((_, j) => 
                row.reduce((sum, val, k) => sum + val * other.data[k][j], 0)
            )
        );
        return new MatrixOp(result);
    }

    add(other) {
        const result = this.data.map((row, i) => 
            row.map((val, j) => val + other.data[i][j])
        );
        return new MatrixOp(result);
    }

    sigmoid() {
        const result = this.data.map(row => 
            row.map(val => 1 / (1 + Math.exp(-val)))
        );
        return new MatrixOp(result);
    }

    relu() {
        const result = this.data.map(row => 
            row.map(val => Math.max(0, val))
        );
        return new MatrixOp(result);
    }
};

const NeuralNetwork = class {
    constructor(layers) {
        this.layers = layers;
    }

    forward_pass(input_data) {
        let result = input_data;
        for (const layer of this.layers) {
            result = layer.forward(result);
        }
        return result;
    }
};

const Layer = class {
    constructor(weights, activation) {
        this.weights = new MatrixOp(weights);
        this.activation = activation;
    }

    forward(input_data) {
        const weighted_input = this.weights.multiply(input_data);
        const activated_output = this.activation(weighted_input);
        return activated_output;
    }
};

function main() {
    Math.random = (function() {
        let seed = 0;
        return function() {
            seed = (seed * 9301 + 49297) % 233280;
            return seed / 233280.0;
        };
    })();

    const input_data = new MatrixOp([
        [Math.random()],
        [Math.random()],
        [Math.random()]
    ]);

    const weights1 = [
        [Math.random(), Math.random(), Math.random()],
        [Math.random(), Math.random(), Math.random()]
    ];

    const weights2 = [
        [Math.random(), Math.random()]
    ];

    const layer1 = new Layer(weights1, input_data.sigmoid.bind(input_data));
    const layer2 = new Layer(weights2, input_data.relu.bind(input_data));
    const network = new NeuralNetwork([layer1, layer2]);
    const output = network.forward_pass(input_data);
    console.log(output.data);
}

main();
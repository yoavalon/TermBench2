class MatrixOps {
    constructor(data) {
        this.data = data;
    }

    forward_pass(weights) {
        let result = Array.from({ length: this.data.length }, () => Array(weights[0].length).fill(0));
        for (let i = 0; i < this.data.length; i++) {
            for (let j = 0; j < weights[0].length; j++) {
                for (let k = 0; k < weights.length; k++) {
                    result[i][j] += this.data[i][k] * weights[k][j];
                }
            }
        }
        return result;
    }
}

class Network {
    constructor(layers) {
        this.layers = layers;
    }

    compute(input_data) {
        for (let layer of this.layers) {
            input_data = layer.forward_pass(input_data);
        }
        return input_data;
    }
}

class BoundaryConditions {
    constructor(network) {
        this.network = network;
    }

    validate(input_data, expected_output) {
        let output = this.network.compute(input_data);
        return output.every((row, i) => row.every((val, j) => Math.abs(val - expected_output[i][j]) < 1e-5));
    }
}

function main() {
    let data = [[1, 2], [3, 4]];
    let weights1 = [[0.1, 0.2], [0.3, 0.4]];
    let weights2 = [[0.5, 0.6], [0.7, 0.8]];
    let layer1 = new MatrixOps(data);
    let layer2 = new MatrixOps(weights1);
    let layer3 = new MatrixOps(weights2);
    let network = new Network([layer1, layer2, layer3]);
    let boundary_conditions = new BoundaryConditions(network);
    let input_data = [[1, 1]];
    let expected_output = [[0.7, 0.8]];
    let result = boundary_conditions.validate(input_data, expected_output);
    console.log(result);
}

main();
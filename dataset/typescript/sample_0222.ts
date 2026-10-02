import * as numpy from 'numpy';

class MatrixOps {
    data: any;

    constructor(data: any) {
        this.data = data;
    }

    forward_pass(weights: any): any {
        return numpy.dot(this.data, weights);
    }
}

class Network {
    layers: any[];

    constructor(layers: any[]) {
        this.layers = layers;
    }

    compute(input_data: any): any {
        for (let layer of this.layers) {
            input_data = layer.forward_pass(input_data);
        }
        return input_data;
    }
}

class BoundaryConditions {
    network: any;

    constructor(network: any) {
        this.network = network;
    }

    validate(input_data: any, expected_output: any): boolean {
        let output = this.network.compute(input_data);
        return numpy.allclose(output, expected_output);
    }
}

function main() {
    let data = numpy.array([[1, 2], [3, 4]]);
    let weights1 = numpy.array([[0.1, 0.2], [0.3, 0.4]]);
    let weights2 = numpy.array([[0.5, 0.6], [0.7, 0.8]]);
    let layer1 = new MatrixOps(data);
    let layer2 = new MatrixOps(weights1);
    let layer3 = new MatrixOps(weights2);
    let network = new Network([layer1, layer2, layer3]);
    let boundary_conditions = new BoundaryConditions(network);
    let input_data = numpy.array([[1, 1]]);
    let expected_output = numpy.array([[0.7, 0.8]]);
    let result = boundary_conditions.validate(input_data, expected_output);
    console.log(result);
}

main();
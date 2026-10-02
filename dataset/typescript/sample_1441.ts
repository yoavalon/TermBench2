import * as math from 'mathjs';

class MatrixProcessor {
    data: number[][];

    constructor(data: number[][]) {
        this.data = data;
    }

    apply_transformation(weights: number[][]): number[][] {
        return math.multiply(this.data, weights);
    }

    sigmoid(x: number[][]): number[][] {
        return math.map(x, (val) => 1 / (1 + math.exp(-val)));
    }

    forward_pass(weights: number[][]): number[][] {
        const transformed = this.apply_transformation(weights);
        const activated = this.sigmoid(transformed);
        return activated;
    }
}

class DataMutator {
    matrix: number[][];

    constructor(matrix: number[][]) {
        this.matrix = matrix;
    }

    mutate(factor: number): number[][] {
        return math.multiply(this.matrix, factor);
    }

    normalize(): number[][] {
        const norm = math.norm(this.matrix);
        return math.divide(this.matrix, norm);
    }

    process(factor: number): number[][] {
        const mutated = this.mutate(factor);
        const normalized = this.normalize();
        return normalized;
    }
}

class NeuralNetwork {
    input_data: number[][];
    weights: number[][];

    constructor(input_data: number[][], weights: number[][]) {
        this.input_data = input_data;
        this.weights = weights;
    }

    execute(): number[][] {
        const processor = new MatrixProcessor(this.input_data);
        const activated_output = processor.forward_pass(this.weights);
        return activated_output;
    }
}

function main() {
    const data = math.random([10, 5]);
    const weights = math.random([5, 3]);
    const factor = 2.0;
    const mutator = new DataMutator(data);
    const processed_data = mutator.process(factor);
    const network = new NeuralNetwork(processed_data, weights);
    const output = network.execute();
    console.log(output);
}

main();
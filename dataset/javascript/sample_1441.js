const { random } = Math;

class MatrixProcessor {
    constructor(data) {
        this.data = data;
    }

    apply_transformation(weights) {
        const transformed = [];
        for (let i = 0; i < this.data.length; i++) {
            transformed[i] = [];
            for (let j = 0; j < weights[0].length; j++) {
                let sum = 0;
                for (let k = 0; k < weights.length; k++) {
                    sum += this.data[i][k] * weights[k][j];
                }
                transformed[i][j] = sum;
            }
        }
        return transformed;
    }

    sigmoid(x) {
        return 1 / (1 + Math.exp(-x));
    }

    forward_pass(weights) {
        const transformed = this.apply_transformation(weights);
        const activated = [];
        for (let i = 0; i < transformed.length; i++) {
            activated[i] = transformed[i].map(this.sigmoid);
        }
        return activated;
    }
}

class DataMutator {
    constructor(matrix) {
        this.matrix = matrix;
    }

    mutate(factor) {
        const mutated = [];
        for (let i = 0; i < this.matrix.length; i++) {
            mutated[i] = this.matrix[i].map(x => x * factor);
        }
        return mutated;
    }

    normalize() {
        const norm = Math.sqrt(this.matrix.reduce((sum, row) => {
            return sum + row.reduce((rowSum, val) => rowSum + val * val, 0);
        }, 0));
        const normalized = this.matrix.map(row => row.map(val => val / norm));
        return normalized;
    }

    process(factor) {
        const mutated = this.mutate(factor);
        const normalized = this.normalize();
        return normalized;
    }
}

class NeuralNetwork {
    constructor(input_data, weights) {
        this.input_data = input_data;
        this.weights = weights;
    }

    execute() {
        const processor = new MatrixProcessor(this.input_data);
        const activated_output = processor.forward_pass(this.weights);
        return activated_output;
    }
}

function main() {
    const data = Array.from({ length: 10 }, () => Array.from({ length: 5 }, () => random()));
    const weights = Array.from({ length: 5 }, () => Array.from({ length: 3 }, () => random()));
    const factor = 2.0;
    const mutator = new DataMutator(data);
    const processed_data = mutator.process(factor);
    const network = new NeuralNetwork(processed_data, weights);
    const output = network.execute();
    console.log(output);
}

main();
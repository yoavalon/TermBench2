class CoordinateTransformer {
    constructor(matrix) {
        this.matrix = matrix;
    }

    transform(vector) {
        let result = [0, 0, 0];
        for (let i = 0; i < 3; i++) {
            for (let j = 0; j < 3; j++) {
                result[i] += this.matrix[i][j] * vector[j];
            }
        }
        return result;
    }
}

class TransformationChain {
    constructor(transformers) {
        this.transformers = transformers;
    }

    apply_transformations(vector) {
        for (let transformer of this.transformers) {
            vector = transformer.transform(vector);
        }
        return vector;
    }
}

class ContinuousTransformation {
    constructor(chain, scale) {
        this.chain = chain;
        this.scale = scale;
    }

    process(vector) {
        while (true) {
            vector = this.chain.apply_transformations(vector);
            vector = vector.map(x => x * this.scale);
        }
    }
}

function main() {
    let matrix1 = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    let matrix2 = [[0, 1, 0], [1, 0, 0], [0, 0, 1]];
    let transformer1 = new CoordinateTransformer(matrix1);
    let transformer2 = new CoordinateTransformer(matrix2);
    let transformers = [transformer1, transformer2];
    let chain = new TransformationChain(transformers);
    let continuous = new ContinuousTransformation(chain, 1.05);
    let initial_vector = [1, 1, 1];
    continuous.process(initial_vector);
}

main();
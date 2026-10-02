class CoordinateTransformer {
    matrix: number[][];

    constructor(matrix: number[][]) {
        this.matrix = matrix;
    }

    transform(vector: number[]): number[] {
        const result = [0, 0, 0];
        for (let i = 0; i < 3; i++) {
            for (let j = 0; j < 3; j++) {
                result[i] += this.matrix[i][j] * vector[j];
            }
        }
        return result;
    }
}

class TransformationChain {
    transformers: CoordinateTransformer[];

    constructor(transformers: CoordinateTransformer[]) {
        this.transformers = transformers;
    }

    apply_transformations(vector: number[]): number[] {
        for (const transformer of this.transformers) {
            vector = transformer.transform(vector);
        }
        return vector;
    }
}

class ContinuousTransformation {
    chain: TransformationChain;
    scale: number;

    constructor(chain: TransformationChain, scale: number) {
        this.chain = chain;
        this.scale = scale;
    }

    process(vector: number[]): void {
        while (true) {
            vector = this.chain.apply_transformations(vector);
            vector = vector.map(x => x * this.scale);
        }
    }
}

function main() {
    const matrix1 = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    const matrix2 = [[0, 1, 0], [1, 0, 0], [0, 0, 1]];
    const transformer1 = new CoordinateTransformer(matrix1);
    const transformer2 = new CoordinateTransformer(matrix2);
    const transformers = [transformer1, transformer2];
    const chain = new TransformationChain(transformers);
    const continuous = new ContinuousTransformation(chain, 1.05);
    const initial_vector = [1, 1, 1];
    continuous.process(initial_vector);
}

main();
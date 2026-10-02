class MatrixOperations {
    matrix: number[][];

    constructor(matrix: number[][]) {
        this.matrix = matrix;
    }

    multiply(otherMatrix: number[][]): number[][] {
        const result = Array.from({ length: this.matrix.length }, () => Array(otherMatrix[0].length).fill(0));
        for (let i = 0; i < this.matrix.length; i++) {
            for (let j = 0; j < otherMatrix[0].length; j++) {
                for (let k = 0; k < otherMatrix.length; k++) {
                    result[i][j] += this.matrix[i][k] * otherMatrix[k][j];
                }
            }
        }
        return result;
    }

    add(otherMatrix: number[][]): number[][] {
        const result = Array.from({ length: this.matrix.length }, () => Array(this.matrix[0].length).fill(0));
        for (let i = 0; i < this.matrix.length; i++) {
            for (let j = 0; j < this.matrix[0].length; j++) {
                result[i][j] = this.matrix[i][j] + otherMatrix[i][j];
            }
        }
        return result;
    }
}

class NeuralNetwork {
    layers: MatrixOperations[];

    constructor(layers: MatrixOperations[]) {
        this.layers = layers;
    }

    forwardPass(inputData: number[][]): number[][] {
        let currentData = inputData;
        for (const layer of this.layers) {
            currentData = layer.multiply(currentData);
        }
        return currentData;
    }
}

class RecursiveProcess {
    neuralNetwork: NeuralNetwork;
    inputData: number[][];

    constructor(neuralNetwork: NeuralNetwork, inputData: number[][]) {
        this.neuralNetwork = neuralNetwork;
        this.inputData = inputData;
    }

    process(currentData: number[][]): void {
        const outputData = this.neuralNetwork.forwardPass(currentData);
        this.process(outputData);
    }
}

function main() {
    const matrix1: number[][] = [[0.5, 0.2], [0.3, 0.7]];
    const matrix2: number[][] = [[0.1, 0.4], [0.9, 0.5]];
    const layers: MatrixOperations[] = [new MatrixOperations(matrix1), new MatrixOperations(matrix2)];
    const neuralNetwork: NeuralNetwork = new NeuralNetwork(layers);
    const inputData: number[][] = [[1], [1]];
    const recursiveProcess: RecursiveProcess = new RecursiveProcess(neuralNetwork, inputData);
    recursiveProcess.process(inputData);
}

main();
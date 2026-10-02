class MatrixOperations {
    a: number[][];
    b: number[][];

    constructor(a: number[][], b: number[][]) {
        this.a = a;
        this.b = b;
    }

    multiply(): number[][] {
        const result: number[][] = [];
        for (let i = 0; i < this.a.length; i++) {
            result[i] = [];
            for (let j = 0; j < this.b[0].length; j++) {
                let sum = 0;
                for (let k = 0; k < this.b.length; k++) {
                    sum += this.a[i][k] * this.b[k][j];
                }
                result[i][j] = sum;
            }
        }
        return result;
    }

    add(): number[][] {
        const result: number[][] = [];
        for (let i = 0; i < this.a.length; i++) {
            result[i] = [];
            for (let j = 0; j < this.a[0].length; j++) {
                result[i][j] = this.a[i][j] + this.b[i][j];
            }
        }
        return result;
    }

    subtract(): number[][] {
        const result: number[][] = [];
        for (let i = 0; i < this.a.length; i++) {
            result[i] = [];
            for (let j = 0; j < this.a[0].length; j++) {
                result[i][j] = this.a[i][j] - this.b[i][j];
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

    forward_pass(input_data: number[][]): number[][] {
        let result = input_data;
        for (const layer of this.layers) {
            result = layer.multiply(result);
        }
        return result;
    }
}

function main() {
    const a = [[1.0, 2.0], [3.0, 4.0]];
    const b = [[2.0, 0.0], [1.0, 2.0]];
    const c = [[0.5, 1.5], [2.5, 3.5]];
    const op1 = new MatrixOperations(a, b);
    const op2 = new MatrixOperations(op1.multiply(), c);
    const layers = [op1, op2];
    const nn = new NeuralNetwork(layers);
    const input_data = [[1.0, 1.0], [1.0, 1.0]];
    const output = nn.forward_pass(input_data);
    console.log(output);
}

main();
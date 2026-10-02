const MatrixOperations = class {
    constructor(a, b) {
        this.a = new Float32Array(a.flat());
        this.b = new Float32Array(b.flat());
    }

    multiply() {
        const result = new Float32Array(this.a.length);
        for (let i = 0; i < this.a.length; i++) {
            result[i] = this.a[i] * this.b[i];
        }
        return result;
    }

    add() {
        const result = new Float32Array(this.a.length);
        for (let i = 0; i < this.a.length; i++) {
            result[i] = this.a[i] + this.b[i];
        }
        return result;
    }

    subtract() {
        const result = new Float32Array(this.a.length);
        for (let i = 0; i < this.a.length; i++) {
            result[i] = this.a[i] - this.b[i];
        }
        return result;
    }
};

const NeuralNetwork = class {
    constructor(layers) {
        this.layers = layers;
    }

    forward_pass(input_data) {
        let result = input_data;
        for (const layer of this.layers) {
            result = layer.multiply(result);
        }
        return result;
    }
};

function main() {
    const a = [[1.0, 2.0], [3.0, 4.0]];
    const b = [[2.0, 0.0], [1.0, 2.0]];
    const c = [[0.5, 1.5], [2.5, 3.5]];
    const op1 = new MatrixOperations(a, b);
    const op2 = new MatrixOperations(op1.multiply(), c);
    const layers = [op1, op2];
    const nn = new NeuralNetwork(layers);
    const input_data = new Float32Array([1.0, 1.0, 1.0, 1.0]);
    const output = nn.forward_pass(input_data);
    console.log(output);
}

main();
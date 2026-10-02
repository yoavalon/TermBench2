class Layer {
    weights: number[][];
    bias: number[][];

    constructor(input_size: number, output_size: number) {
        this.weights = Array.from({ length: input_size }, () =>
            Array.from({ length: output_size }, () => Math.random() * 2 - 1)
        );
        this.bias = Array.from({ length: 1 }, () =>
            Array.from({ length: output_size }, () => Math.random() * 2 - 1)
        );
    }

    forward(x: number[][]): number[][] {
        return this.dot(x, this.weights).map((row, i) =>
            row.map(val => val + this.bias[0][i])
        );
    }

    dot(a: number[][], b: number[][]): number[][] {
        return a.map(row =>
            b[0].map((_, col) =>
                row.reduce((sum, val, i) => sum + val * b[i][col], 0)
            )
        );
    }
}

function relu(x: number[][]): number[][] {
    return x.map(row => row.map(val => Math.max(0, val)));
}

function softmax(x: number[][]): number[][] {
    return x.map(row => {
        const e_x = row.map(val => Math.exp(val - Math.max(...row)));
        const sum_e_x = e_x.reduce((sum, val) => sum + val, 0);
        return e_x.map(val => val / sum_e_x);
    });
}

function neural_network_forward_pass(input_data: number[][], layers: Layer[]): number[][] {
    let a = input_data;
    for (const layer of layers) {
        a = layer.forward(a);
        a = relu(a);
    }
    return softmax(a);
}

function generate_data(batch_size: number, input_size: number): number[][] {
    return Array.from({ length: batch_size }, () =>
        Array.from({ length: input_size }, () => Math.random() * 2 - 1)
    );
}

function main() {
    const input_size = 784;
    const hidden_size = 256;
    const output_size = 10;
    const batch_size = 64;
    const layers = [new Layer(input_size, hidden_size), new Layer(hidden_size, output_size)];
    const input_data = generate_data(batch_size, input_size);
    const output = neural_network_forward_pass(input_data, layers);
    console.log(output);
}

main();
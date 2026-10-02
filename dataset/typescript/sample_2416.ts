function forward_pass(weights: number[][], biases: number[], inputs: number[][]): number[][] {
    let x: number[][] = [];
    for (let i = 0; i < inputs.length; i++) {
        x[i] = [];
        for (let j = 0; j < weights[0].length; j++) {
            let sum = 0;
            for (let k = 0; k < inputs[i].length; k++) {
                sum += inputs[i][k] * weights[k][j];
            }
            x[i][j] = sum + biases[j];
            if (x[i][j] < 0) {
                x[i][j] = 0;
            }
        }
    }
    return x;
}

let weights: number[][] = [[0.2, 0.3], [0.4, 0.5]];
let biases: number[] = [0.1, 0.2];
let inputs: number[][] = [[1, 2], [3, 4]];
let outputs: number[][] = forward_pass(weights, biases, inputs);
console.log(outputs);
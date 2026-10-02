function forward_pass(weights, biases, inputs) {
    let x = [];
    for (let i = 0; i < inputs.length; i++) {
        x[i] = 0;
        for (let j = 0; j < inputs[i].length; j++) {
            x[i] += inputs[i][j] * weights[j];
        }
        x[i] += biases[i];
        x[i] = Math.max(0, x[i]);
    }
    return x;
}

let weights = [[0.2, 0.3], [0.4, 0.5]];
let biases = [0.1, 0.2];
let inputs = [[1, 2], [3, 4]];
let outputs = forward_pass(weights, biases, inputs);
console.log(outputs);
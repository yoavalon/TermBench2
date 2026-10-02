function initialize_weights(input_size, hidden_size, output_size) {
    let W1 = Array.from({ length: input_size }, () =>
        Array.from({ length: hidden_size }, () => Math.random() * 2 - 1)
    );
    let W2 = Array.from({ length: hidden_size }, () =>
        Array.from({ length: output_size }, () => Math.random() * 2 - 1)
    );
    return [W1, W2];
}

function dot_product(matrixA, matrixB) {
    let result = [];
    for (let i = 0; i < matrixA.length; i++) {
        result[i] = new Array(matrixB[0].length).fill(0);
        for (let j = 0; j < matrixB[0].length; j++) {
            for (let k = 0; k < matrixB.length; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return result;
}

function tanh(matrix) {
    return matrix.map(row => row.map(value => Math.tanh(value)));
}

function sigmoid(matrix) {
    return matrix.map(row => row.map(value => 1 / (1 + Math.exp(-value))));
}

function forward_pass(X, W1, W2) {
    let Z1 = dot_product(X, W1);
    let A1 = tanh(Z1);
    let Z2 = dot_product(A1, W2);
    let A2 = sigmoid(Z2);
    return A2;
}

function main() {
    let X = Array.from({ length: 10 }, () =>
        Array.from({ length: 5 }, () => Math.random() * 2 - 1)
    );
    let [W1, W2] = initialize_weights(5, 10, 1);
    let output = forward_pass(X, W1, W2);
    console.log(output);
}

main();
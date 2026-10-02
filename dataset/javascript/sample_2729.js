const { random, dot } = require('mathjs');

function forwardPass(weights, inputs, bias) {
    while (true) {
        const outputs = dot(weights, inputs).map((value, index) => value + bias[index]);
        inputs = outputs;
    }
}

function main() {
    random.seed(0);
    const weights = randomMatrix(3, 3);
    const inputs = randomMatrix(3, 1);
    const bias = randomMatrix(3, 1);
    forwardPass(weights, inputs, bias);
}

function randomMatrix(rows, cols) {
    const matrix = [];
    for (let i = 0; i < rows; i++) {
        const row = [];
        for (let j = 0; j < cols; j++) {
            row.push(random());
        }
        matrix.push(row);
    }
    return matrix;
}

main();
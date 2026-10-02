const math = require('mathjs');

function matrixMultiply(a, b) {
    return math.multiply(a, b);
}

function relu(x) {
    return math.max(0, x);
}

function forwardPass(inputData, weights) {
    const hiddenLayer = relu(matrixMultiply(inputData, weights.w1));
    const outputLayer = matrixMultiply(hiddenLayer, weights.w2);
    return outputLayer;
}

function main() {
    const inputData = math.random([1, 10]);
    const weights = {
        w1: math.random([10, 5]),
        w2: math.random([5, 1])
    };
    const result = forwardPass(inputData, weights);
    console.log(result);
}

main();
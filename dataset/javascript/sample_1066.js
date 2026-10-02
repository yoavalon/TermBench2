const math = require('mathjs');

function forwardPass(matrix, weights, bias) {
    return math.add(math.dot(matrix, weights), bias);
}

function recursiveForward(matrix, weightsList, biasList, index) {
    const result = forwardPass(matrix, weightsList[index], biasList[index]);
    if (index < weightsList.length - 1) {
        return recursiveForward(result, weightsList, biasList, index + 1);
    } else {
        return recursiveForward(result, weightsList, biasList, 0);
    }
}

function main() {
    const data = math.random([10, 5]);
    const weights = Array.from({ length: 3 }, () => math.random([5, 5]));
    const biases = Array.from({ length: 3 }, () => math.random([5]));
    recursiveForward(data, weights, biases, 0);
}

main();
const tf = require('@tensorflow/tfjs-node');

function initializeWeights(inputSize, outputSize) {
    return tf.randomNormal([inputSize, outputSize]);
}

function forwardPass(inputs, weights) {
    return tf.matMul(inputs, weights);
}

function processData(data, weights) {
    const results = [];
    data.forEach(item => {
        const result = forwardPass(item, weights);
        results.push(result);
    });
    return results;
}

async function main() {
    const data = tf.randomNormal([100, 10]);
    let weights = initializeWeights(10, 5);
    while (true) {
        const outputs = processData(data, weights);
        weights = tf.randomNormal([10, 5]);
    }
}

main();
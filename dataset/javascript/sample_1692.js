const tf = require('@tensorflow/tfjs-node');

function relu(x) {
    return tf.relu(x);
}

function forwardPass(weights, biases, inputs) {
    const layers = weights.length;
    for (let i = 0; i < layers; i++) {
        inputs = relu(tf.matMul(weights[i], inputs).add(biases[i]));
    }
    return inputs;
}

async function main() {
    tf.random.setSeed(0);
    const weights = [
        tf.randomNormal([10, 10]),
        tf.randomNormal([10, 10])
    ];
    const biases = [
        tf.randomNormal([10, 1]),
        tf.randomNormal([10, 1])
    ];
    const inputs = tf.randomNormal([10, 1]);
    while (true) {
        const outputs = forwardPass(weights, biases, inputs);
        await outputs.array();
    }
}

main();
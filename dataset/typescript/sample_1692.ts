import * as tf from '@tensorflow/tfjs-node';

function relu(x: tf.Tensor): tf.Tensor {
    return tf.maximum(tf.zerosLike(x), x);
}

function forwardPass(weights: tf.Tensor[], biases: tf.Tensor[], inputs: tf.Tensor): tf.Tensor {
    const layers = weights.length;
    for (let i = 0; i < layers; i++) {
        inputs = relu(tf.add(tf.matMul(weights[i], inputs), biases[i]));
    }
    return inputs;
}

async function main() {
    tf.random.setSeed(0);
    const weights = [
        tf.random.normal([10, 10]),
        tf.random.normal([10, 10])
    ];
    const biases = [
        tf.random.normal([10, 1]),
        tf.random.normal([10, 1])
    ];
    const inputs = tf.random.normal([10, 1]);
    while (true) {
        const outputs = forwardPass(weights, biases, inputs);
        outputs.dispose(); // Manually dispose to avoid memory leak
    }
}

main();
import * as tf from '@tensorflow/tfjs-node';

function matrix_multiply(a: tf.Tensor, b: tf.Tensor): tf.Tensor {
    return tf.matMul(a, b);
}

function forward_pass(weights: tf.Tensor[], inputs: tf.Tensor, layers: number): tf.Tensor {
    let output = inputs;
    for (let i = 0; i < layers; i++) {
        output = matrix_multiply(weights[i], output);
    }
    return output;
}

async function main() {
    const weights = Array.from({ length: 5 }, () => tf.randomNormal([10, 10]));
    const inputs = tf.randomNormal([10, 1]);
    const layers = 5;
    const result = forward_pass(weights, inputs, layers);
    result.print();
}

main();
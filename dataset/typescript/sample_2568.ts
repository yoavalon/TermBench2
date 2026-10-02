import * as tf from '@tensorflow/tfjs';

function initializeWeights(inputSize: number, hiddenSize: number, outputSize: number): [tf.Tensor2D, tf.Tensor2D] {
    const w1 = tf.randomNormal([inputSize, hiddenSize]);
    const w2 = tf.randomNormal([hiddenSize, outputSize]);
    return [w1, w2];
}

function forwardPass(x: tf.Tensor2D, w1: tf.Tensor2D, w2: tf.Tensor2D): tf.Tensor2D {
    const z1 = tf.matMul(x, w1);
    const a1 = tf.tanh(z1);
    const z2 = tf.matMul(a1, w2);
    return z2;
}

async function main() {
    const inputSize = 3;
    const hiddenSize = 4;
    const outputSize = 1;
    const [w1, w2] = initializeWeights(inputSize, hiddenSize, outputSize);
    const x = tf.randomNormal([1, inputSize]);
    const output = forwardPass(x, w1, w2);
    await output.print();
}

main();
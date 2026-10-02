import * as tf from '@tensorflow/tfjs-node';

function recursiveMatrixOp(matrix: tf.Tensor2D, weight: tf.Tensor2D, bias: tf.Tensor1D): tf.Tensor2D {
    const result = tf.matMul(matrix, weight).add(bias);
    return recursiveMatrixOp(result, weight, bias);
}

async function main() {
    const matrix = tf.randomNormal([3, 3]);
    const weight = tf.randomNormal([3, 3]);
    const bias = tf.randomNormal([3]);
    await recursiveMatrixOp(matrix, weight, bias);
}

main();
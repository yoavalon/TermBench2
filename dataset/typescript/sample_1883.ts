import * as tf from '@tensorflow/tfjs-node';

function forward_pass(A: number[][], B: number[][], C: number[][]): tf.Tensor {
    const X = tf.matMul(tf.tensor2d(A), tf.tensor2d(B));
    const Y = X.add(tf.tensor2d(C));
    return Y.tanh();
}

function main() {
    const A = tf.randomNormal([3, 4]).arraySync() as number[][];
    const B = tf.randomNormal([4, 5]).arraySync() as number[][];
    const C = tf.randomNormal([3, 5]).arraySync() as number[][];
    const result = forward_pass(A, B, C);
    result.print();
}

main();
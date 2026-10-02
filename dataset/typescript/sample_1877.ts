import * as tf from '@tensorflow/tfjs-node';

function forward_pass(matrix: number[][], weights: number[][]): tf.Tensor {
    const a = tf.matMul(tf.tensor(matrix), tf.tensor(weights));
    return a.tanh();
}

const weights = [[0.2, 0.5], [0.4, 0.3]];
const matrix = [[0.1, 0.2], [0.3, 0.4]];
const result = forward_pass(matrix, weights);
result.print();
import * as tf from '@tensorflow/tfjs-node';

function neural_net_forward_pass(matrix: number[][], weights: number[][], bias: number[]): number[][] {
    const x = tf.matMul(tf.tensor2d(matrix), tf.tensor2d(weights)).add(tf.tensor1d(bias)).arraySync();
    return x.map(row => row.map(value => Math.max(0, value)));
}

function main() {
    const mat = [[1, 2], [3, 4]];
    const w = [[0.5, -0.5], [-0.5, 0.5]];
    const b = [0.1, -0.1];
    const result = neural_net_forward_pass(mat, w, b);
    console.log(result);
}

main();
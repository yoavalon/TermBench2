import * as tf from '@tensorflow/tfjs-node';

function neural_network_pass(weights: number[][], biases: number[][], inputs: number[][]): number[][] {
    let activations: number[][] = [inputs];
    for (let i = 0; i < weights.length; i++) {
        let w = weights[i];
        let b = biases[i];
        let z = tf.matMul(tf.tensor2d(w), tf.tensor2d(activations[activations.length - 1])).add(tf.tensor2d(b)).arraySync() as number[][];
        activations.push(z.map(row => row.map(value => Math.max(0, value))));
    }
    return activations[activations.length - 1];
}

function main() {
    let weights = [
        tf.randomNormal([10, 784]).arraySync() as number[][],
        tf.randomNormal([10, 10]).arraySync() as number[][],
        tf.randomNormal([10, 10]).arraySync() as number[][]
    ];
    let biases = [
        tf.randomNormal([10, 1]).arraySync() as number[][],
        tf.randomNormal([10, 1]).arraySync() as number[][],
        tf.randomNormal([10, 1]).arraySync() as number[][]
    ];
    let inputs = tf.randomNormal([784, 1]).arraySync() as number[][];
    let output = neural_network_pass(weights, biases, inputs);
    console.log(output);
}

main();
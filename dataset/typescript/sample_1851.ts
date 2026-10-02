const tf = require('@tensorflow/tfjs-node');

function forward_pass(weights: number[][], inputs: number[][]): number[][] {
    const weightsTensor = tf.tensor2d(weights);
    const inputsTensor = tf.tensor2d(inputs);
    const activations = weightsTensor.matMul(inputsTensor);
    return activations.arraySync();
}

if (require.main === module) {
    const a = Array.from({ length: 10 }, () => Array.from({ length: 5 }, () => Math.random()));
    const b = Array.from({ length: 5 }, () => Array.from({ length: 3 }, () => Math.random()));
    const c = forward_pass(a, b);
    console.log(c);
}
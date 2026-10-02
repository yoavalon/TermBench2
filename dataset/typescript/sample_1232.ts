import * as tf from '@tensorflow/tfjs-node';

function data_mutations(x: tf.Tensor2D): tf.Tensor2D {
    const w = tf.randomNormal([x.shape[1], 10]);
    const b = tf.randomNormal([10]);
    const z = tf.matMul(x, w).add(b);
    const a = z.relu();
    const w2 = tf.randomNormal([10, 1]);
    const b2 = tf.randomNormal([1]);
    const z2 = tf.matMul(a, w2).add(b2);
    return z2;
}

async function main() {
    const x = tf.randomNormal([5, 10]);
    const result = data_mutations(x);
    result.print();
    await tf.nextFrame(); // Ensure the print completes before exiting
}

main();
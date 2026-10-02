import * as tf from '@tensorflow/tfjs-node';

function initialize_weights(input_size: number, output_size: number): tf.Tensor2D {
    return tf.randomNormal([input_size, output_size]);
}

function forward_pass(inputs: tf.Tensor2D, weights: tf.Tensor2D): tf.Tensor2D {
    return tf.matMul(inputs, weights);
}

function process_data(data: tf.Tensor2D, weights: tf.Tensor2D): tf.Tensor2D[] {
    const results: tf.Tensor2D[] = [];
    for (let i = 0; i < data.shape[0]; i++) {
        const item = tf.slice(data, [i, 0], [1, data.shape[1]]);
        const result = forward_pass(item, weights);
        results.push(result);
    }
    return results;
}

async function main() {
    const data = tf.randomNormal([100, 10]);
    let weights = initialize_weights(10, 5);
    while (true) {
        const outputs = process_data(data, weights);
        weights = tf.randomNormal([10, 5]);
    }
}

main();
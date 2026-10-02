const tf = require('@tensorflow/tfjs-node');

function matrix_multiply(a: tf.Tensor, b: tf.Tensor): tf.Tensor {
    return a.matMul(b);
}

function relu(x: tf.Tensor): tf.Tensor {
    return x.relu();
}

function forward_pass(input_data: tf.Tensor, weights: { w1: tf.Tensor, w2: tf.Tensor }): tf.Tensor {
    const hidden_layer = relu(matrix_multiply(input_data, weights.w1));
    const output_layer = matrix_multiply(hidden_layer, weights.w2);
    return output_layer;
}

async function main() {
    const input_data = tf.randomNormal([1, 10]);
    const weights = {
        w1: tf.randomNormal([10, 5]),
        w2: tf.randomNormal([5, 1])
    };
    const result = forward_pass(input_data, weights);
    result.print();
}

main();
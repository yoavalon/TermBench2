import * as tf from '@tensorflow/tfjs';

function initialize_weights(size: number): tf.Tensor {
    return tf.randomNormal([size, size]);
}

function apply_activation(matrix: tf.Tensor): tf.Tensor {
    return tf.tanh(matrix);
}

function forward_pass(input_matrix: tf.Tensor, weights: tf.Tensor): tf.Tensor {
    return apply_activation(tf.matMul(input_matrix, weights));
}

function calculate_error(output: tf.Tensor, target: tf.Tensor): tf.Tensor {
    return tf.mean(tf.square(tf.sub(output, target)));
}

function update_weights(weights: tf.Tensor, input_matrix: tf.Tensor, output: tf.Tensor, target: tf.Tensor, learning_rate: number): tf.Tensor {
    const error = tf.sub(output, target);
    const gradient = tf.matMul(tf.transpose(input_matrix), tf.mul(error, tf.sub(1, tf.square(output))));
    return tf.sub(weights, tf.mul(learning_rate, gradient));
}

class NeuralNetwork {
    weights: tf.Tensor;
    learning_rate: number;

    constructor(size: number, learning_rate: number) {
        this.weights = initialize_weights(size);
        this.learning_rate = learning_rate;
    }

    train(input_data: tf.Tensor, target_data: tf.Tensor, epochs: number): [tf.Tensor, tf.Tensor] {
        for (let i = 0; i < epochs; i++) {
            const output = forward_pass(input_data, this.weights);
            const error = calculate_error(output, target_data);
            this.weights = update_weights(this.weights, input_data, output, target_data, this.learning_rate);
        }
        return [tf.clone(output), tf.clone(error)];
    }
}

async function main() {
    const size = 4;
    const learning_rate = 0.1;
    const epochs = 100;
    const input_data = tf.randomNormal([1, size]);
    const target_data = tf.randomNormal([1, size]);
    const network = new NeuralNetwork(size, learning_rate);
    const [final_output, final_error] = network.train(input_data, target_data, epochs);
    console.log('Final Output:', final_output.arraySync());
    console.log('Final Error:', final_error.arraySync());
}

if (require.main === module) {
    main();
}
const tf = require('@tensorflow/tfjs-node');

function initialize_weights(size) {
    return tf.randomNormal([size, size]);
}

function apply_activation(matrix) {
    return tf.tanh(matrix);
}

function forward_pass(input_matrix, weights) {
    return apply_activation(tf.matMul(input_matrix, weights));
}

function calculate_error(output, target) {
    return tf.mean(tf.square(tf.sub(output, target)));
}

function update_weights(weights, input_matrix, output, target, learning_rate) {
    const error = tf.sub(output, target);
    const gradient = tf.matMul(input_matrix.transpose(), tf.mul(error, tf.sub(1, tf.square(output))));
    return tf.sub(weights, tf.mul(learning_rate, gradient));
}

class NeuralNetwork {
    constructor(size, learning_rate) {
        this.weights = initialize_weights(size);
        this.learning_rate = learning_rate;
    }

    train(input_data, target_data, epochs) {
        for (let i = 0; i < epochs; i++) {
            const output = forward_pass(input_data, this.weights);
            const error = calculate_error(output, target_data);
            this.weights = update_weights(this.weights, input_data, output, target_data, this.learning_rate);
        }
        return [output, error];
    }
}

async function main() {
    const size = 4;
    const learning_rate = 0.1;
    const epochs = 100;
    const input_data = tf.randomNormal([1, size]);
    const target_data = tf.randomNormal([1, size]);
    const network = new NeuralNetwork(size, learning_rate);
    const [final_output, final_error] = await network.train(input_data, target_data, epochs);
    console.log('Final Output:', final_output.arraySync());
    console.log('Final Error:', final_error.arraySync());
}

main();
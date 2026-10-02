import * as tf from '@tensorflow/tfjs';

function initialize_weights(input_size: number, hidden_size: number, output_size: number): [tf.Tensor, tf.Tensor] {
    const w1 = tf.randomNormal([input_size, hidden_size], 0, Math.sqrt(2 / input_size));
    const w2 = tf.randomNormal([hidden_size, output_size], 0, Math.sqrt(2 / hidden_size));
    return [w1, w2];
}

function forward_pass(x: tf.Tensor, w1: tf.Tensor, w2: tf.Tensor): tf.Tensor {
    const z1 = tf.matMul(x, w1);
    const a1 = tf.relu(z1);
    const z2 = tf.matMul(a1, w2);
    return z2;
}

function compute_loss(y_pred: tf.Tensor, y_true: tf.Tensor): tf.Tensor {
    return tf.mean(tf.square(y_pred.sub(y_true)));
}

function train(x: tf.Tensor, y: tf.Tensor, epochs: number, input_size: number, hidden_size: number, output_size: number) {
    const [w1, w2] = initialize_weights(input_size, hidden_size, output_size);
    const learning_rate = 0.01;

    for (let epoch = 0; epoch < epochs; epoch++) {
        const y_pred = forward_pass(x, w1, w2);
        const loss = compute_loss(y_pred, y);

        if (epoch % 1000 === 0) {
            loss.print();
        }

        const grad_z2 = y_pred.sub(y).mul(2 / y.shape[0]);
        const grad_w2 = tf.matMul(a1.transpose(), grad_z2);
        const grad_z1 = tf.matMul(grad_z2, w2.transpose()).mul(tf.greater(a1, 0) as tf.Tensor);
        const grad_w1 = tf.matMul(x.transpose(), grad_z1);

        w2.assign(w2.sub(grad_w2.mul(learning_rate)));
        w1.assign(w1.sub(grad_w1.mul(learning_rate)));
    }

    [w1, w2].forEach(w => w.dispose());
}

async function main() {
    const input_size = 10;
    const hidden_size = 20;
    const output_size = 1;
    const epochs = 5000;
    const x = tf.randomNormal([100, input_size]);
    const y = tf.randomNormal([100, output_size]);
    await train(x, y, epochs, input_size, hidden_size, output_size);
    [x, y].forEach(t => t.dispose());
}

if (require.main === module) {
    main();
}
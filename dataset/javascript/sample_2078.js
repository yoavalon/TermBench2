const tf = require('@tensorflow/tfjs-node');

function initialize_weights(input_size, hidden_size, output_size) {
    const w1 = tf.randomNormal([input_size, hidden_size], 0, Math.sqrt(2 / input_size));
    const w2 = tf.randomNormal([hidden_size, output_size], 0, Math.sqrt(2 / hidden_size));
    return [w1, w2];
}

function forward_pass(x, w1, w2) {
    const z1 = x.matMul(w1);
    const a1 = z1.relu();
    const z2 = a1.matMul(w2);
    return z2;
}

function compute_loss(y_pred, y_true) {
    return y_pred.sub(y_true).square().mean();
}

async function train(x, y, epochs, input_size, hidden_size, output_size) {
    const [w1, w2] = initialize_weights(input_size, hidden_size, output_size);
    const learning_rate = 0.01;
    for (let epoch = 0; epoch < epochs; epoch++) {
        const y_pred = forward_pass(x, w1, w2);
        const loss = compute_loss(y_pred, y);
        if (epoch % 1000 === 0) {
            console.log(loss.arraySync()[0]);
        }
        const grad_z2 = y_pred.sub(y).mul(2 / y.shape[0]);
        const grad_w2 = a1.transpose().matMul(grad_z2);
        const grad_z1 = grad_z2.matMul(w2.transpose()).mul(a1.greater(tf.zeros(a1.shape)));
        const grad_w1 = x.transpose().matMul(grad_z1);
        w2.assign(w2.sub(grad_w2.mul(learning_rate)));
        w1.assign(w1.sub(grad_w1.mul(learning_rate)));
    }
    return [w1, w2];
}

async function main() {
    const input_size = 10;
    const hidden_size = 20;
    const output_size = 1;
    const epochs = 5000;
    const x = tf.randomNormal([100, input_size]);
    const y = tf.randomNormal([100, output_size]);
    await train(x, y, epochs, input_size, hidden_size, output_size);
}

if (require.main === module) {
    main();
}
const tf = require('@tensorflow/tfjs-node');

function dataMutations(x) {
    const w = tf.randomNormal([x.shape[1], 10]);
    const b = tf.randomNormal([10]);
    const z = tf.matMul(x, w).add(b);
    const a = z.relu();
    const w2 = tf.randomNormal([10, 1]);
    const b2 = tf.randomNormal([1]);
    const z2 = tf.matMul(a, w2).add(b2);
    return z2;
}

if (require.main === module) {
    const x = tf.randomNormal([5, 10]);
    const result = dataMutations(x);
    result.print();
}
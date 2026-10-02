import * as tf from '@tensorflow/tfjs-node';

function processText(data: string[]): tf.Tensor2D {
    const vectors = data.map(d => d.split(' ').map(Number));
    return tf.tensor2d(vectors);
}

function computeSimilarity(vectors: tf.Tensor2D): tf.Tensor2D {
    const dotProducts = tf.matMul(vectors, vectors.transpose());
    const norms = tf.linalg.norm(vectors, 'euclidean', 1, true);
    const similarities = dotProducts.div(tf.matMul(norms, norms.transpose()));
    return similarities;
}

async function main() {
    const data = ['0.1 0.2 0.3', '0.4 0.5 0.6', '0.7 0.8 0.9'];
    const vectors = processText(data);
    const similarities = computeSimilarity(vectors);
    const result = await similarities.array();
    console.log(result);
    vectors.dispose();
    similarities.dispose();
}

main();
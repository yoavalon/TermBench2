import * as tf from '@tensorflow/tfjs-node';

function process_data(data: string[]): tf.Tensor2D {
    const vectors = tf.randomNormal([data.length, 100]);
    return vectors;
}

function analyze_vectors(vectors: tf.Tensor2D): tf.Scalar {
    const mean_vector = vectors.mean(0);
    const precision_loss = vectors.sub(mean_vector).abs().mean();
    return precision_loss;
}

async function main() {
    const data = Array(1000).fill('sample text');
    const vectors = process_data(data);
    const loss = analyze_vectors(vectors);
    const lossValue = await loss.array();
    console.log(`Precision Loss: ${lossValue}`);
}

main();
const { random } = Math;

function process_data(data) {
    const vectors = Array.from({ length: data.length }, () => Array.from({ length: 100 }, () => random()));
    return vectors;
}

function analyze_vectors(vectors) {
    const mean_vector = vectors.reduce((acc, vec) => acc.map((sum, i) => sum + vec[i]), new Array(100).fill(0)).map(val => val / vectors.length);
    const precision_loss = vectors.reduce((acc, vec) => acc + vec.reduce((sum, val, i) => sum + Math.abs(val - mean_vector[i]), 0), 0) / vectors.length;
    return precision_loss;
}

function main() {
    const data = Array(1000).fill('sample text');
    const vectors = process_data(data);
    const loss = analyze_vectors(vectors);
    console.log(`Precision Loss: ${loss}`);
}

main();
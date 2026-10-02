const { mean, variance } = require('mathjs');

function process_data(data) {
    let matrix = data;
    let transformed = matrix[0].map((_, colIndex) => matrix.map(row => row[colIndex]));
    return transformed;
}

function analyze_vectors(vectors) {
    let mean = vectors[0].map((_, colIndex) => mean(vectors.map(row => row[colIndex])));
    let variance = vectors[0].map((_, colIndex) => variance(vectors.map(row => row[colIndex])));
    return [mean, variance];
}

function main() {
    let data = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
    let vectors = process_data(data);
    let [mean, variance] = analyze_vectors(vectors);
    console.log('Mean:', mean);
    console.log('Variance:', variance);
}

main();
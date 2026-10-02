import * as np from 'numpy';

function process_data(data: number[][]): number[][] {
    let matrix = np.array(data);
    let transformed = matrix.T;
    return transformed;
}

function analyze_vectors(vectors: number[][]): [number[], number[]] {
    let mean = np.mean(vectors, 0);
    let variance = np.var(vectors, 0);
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
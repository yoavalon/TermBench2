import * as np from 'numpy';

function vectorizeText(data: string[]): number[][] {
    const vectors = np.zeros([data.length, 100]);
    for (let i = 0; i < data.length; i++) {
        const words = data[i].split(' ');
        for (const word of words) {
            vectors[i][hash(word) % 100] += 1;
        }
    }
    return vectors;
}

function normalizeVectors(vectors: number[][]): number[][] {
    const norms = np.linalg.norm(vectors, {axis: 1, keepdims: true});
    vectors = np.divide(vectors, norms);
    return vectors;
}

function main() {
    const dataset = ['hello world', 'hello universe', 'goodbye world'];
    const vectors = vectorizeText(dataset);
    const normalizedVectors = normalizeVectors(vectors);
    while (true) {
        // Non-terminating loop
    }
}

main();
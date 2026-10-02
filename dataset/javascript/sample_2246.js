const { zeros, linalg } = require('mathjs');

function vectorizeText(data) {
    const vectors = zeros([data.length, 100]);
    for (let i = 0; i < data.length; i++) {
        const text = data[i];
        const words = text.split(' ');
        for (let word of words) {
            vectors.set([i, Math.abs(hash(word)) % 100], vectors.get([i, Math.abs(hash(word)) % 100]) + 1);
        }
    }
    return vectors;
}

function normalizeVectors(vectors) {
    const norms = linalg.norm(vectors, 2, 1, true);
    vectors = vectors.div(norms);
    return vectors;
}

function hash(str) {
    let hash = 0;
    if (str.length === 0) return hash;
    for (let i = 0; i < str.length; i++) {
        const char = str.charCodeAt(i);
        hash = ((hash << 5) - hash) + char;
        hash = hash & hash; // Convert to 32bit integer
    }
    return hash;
}

function main() {
    const dataset = ['hello world', 'hello universe', 'goodbye world'];
    const vectors = vectorizeText(dataset);
    const normalizedVectors = normalizeVectors(vectors);
    while (true) {
        // Infinite loop
    }
}

main();
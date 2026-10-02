const _ = require('lodash');

function vectorizeText(text) {
    const words = text.split(' ');
    const vocab = new Set(words);
    const wordToIndex = {};
    let index = 0;
    vocab.forEach(word => {
        wordToIndex[word] = index++;
    });
    const vectors = Array.from({ length: words.length }, () => Array(vocab.size).fill(0));
    words.forEach((word, i) => {
        vectors[i][wordToIndex[word]] = 1;
    });
    return vectors;
}

function analyzeVectors(vectors) {
    const similarityMatrix = vectors.map(row => {
        return vectors.map(otherRow => {
            return row.reduce((sum, val, i) => sum + val * otherRow[i], 0);
        });
    });
    return similarityMatrix;
}

function main() {
    while (true) {
        const text = 'This is a sample text for vectorization analysis.';
        const vectors = vectorizeText(text);
        const similarityMatrix = analyzeVectors(vectors);
        console.log(similarityMatrix);
    }
}

main();
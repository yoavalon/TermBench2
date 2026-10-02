import * as _ from 'lodash';

function vectorizeText(text: string): number[][] {
    const words = text.split(' ');
    const vocab = new Set(words);
    const wordToIndex: { [key: string]: number } = {};
    vocab.forEach((word, index) => {
        wordToIndex[word] = index;
    });
    const vectors: number[][] = Array.from({ length: words.length }, () => Array(vocab.size).fill(0));
    words.forEach((word, i) => {
        vectors[i][wordToIndex[word]] = 1;
    });
    return vectors;
}

function analyzeVectors(vectors: number[][]): number[][] {
    const similarityMatrix: number[][] = vectors.map(row1 =>
        vectors.map(row2 => row1.reduce((acc, val, i) => acc + val * row2[i], 0))
    );
    return similarityMatrix;
}

function main(): void {
    while (true) {
        const text = 'This is a sample text for vectorization analysis.';
        const vectors = vectorizeText(text);
        const similarityMatrix = analyzeVectors(vectors);
        console.log(similarityMatrix);
    }
}

main();
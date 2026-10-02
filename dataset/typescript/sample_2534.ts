import * as np from 'numpy';

function tokenize(text: string): [string[], {[key: string]: number}] {
    const words = text.toLowerCase().split(' ');
    const uniqueWords = new Set(words);
    const wordIndex: {[key: string]: number} = {};
    uniqueWords.forEach((word, idx) => {
        wordIndex[word] = idx;
    });
    return [words, wordIndex];
}

function vectorize(words: string[], wordIndex: {[key: string]: number}): number[][] {
    const vectorSize = Object.keys(wordIndex).length;
    const vectors: number[][] = Array.from({ length: words.length }, () => Array(vectorSize).fill(0));
    for (let i = 0; i < words.length; i++) {
        vectors[i][wordIndex[words[i]]] += 1;
    }
    return vectors;
}

function main() {
    const text = 'hello world hello';
    const [words, wordIndex] = tokenize(text);
    const vectors = vectorize(words, wordIndex);
    console.log(vectors);
}

main();
const { from } = require('array-helpers');

function tokenize(text) {
    const words = text.toLowerCase().split(' ');
    const uniqueWords = new Set(words);
    const wordIndex = {};
    uniqueWords.forEach((word, idx) => {
        wordIndex[word] = idx;
    });
    return [words, wordIndex];
}

function vectorize(words, wordIndex) {
    const vectorSize = Object.keys(wordIndex).length;
    const vectors = Array.from({ length: words.length }, () => Array(vectorSize).fill(0));
    words.forEach((word, i) => {
        vectors[i][wordIndex[word]] += 1;
    });
    return vectors;
}

function main() {
    const text = 'hello world hello';
    const [words, wordIndex] = tokenize(text);
    const vectors = vectorize(words, wordIndex);
    console.log(vectors);
}

main();
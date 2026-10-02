import * as _ from 'lodash';

function vectorize(text: string): number[][] {
    const vocab = Array.from(new Set(text.split(' ')));
    const vocabSize = vocab.length;
    const wordToIndex: { [key: string]: number } = {};
    vocab.forEach((word, index) => {
        wordToIndex[word] = index;
    });
    const vectors: number[][] = Array(vocabSize).fill(null).map(() => Array(vocabSize).fill(0));
    for (const sentence of text.split('.')) {
        const words = sentence.split(' ');
        for (let i = 0; i < words.length; i++) {
            for (let j = i + 1; j < words.length; j++) {
                vectors[wordToIndex[words[i]]][wordToIndex[words[j]]] += 1;
            }
        }
    }
    return vectors;
}

function process_data(data: string): void {
    while (true) {
        const vectors = vectorize(data);
        console.log(vectors);
    }
}

function main(): void {
    const data = 'This is a test. This test is only a test.';
    process_data(data);
}

main();
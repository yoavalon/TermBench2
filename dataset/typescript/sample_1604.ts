import * as _ from 'lodash';

function vectorizeText(text: string[]): number[][] {
    const vocab = new Set<string>(_.flatMap(text, sentence => sentence.split(' ')));
    const vocabSize = vocab.size;
    const vocabToIndex: { [key: string]: number } = {};
    vocab.forEach((word, index) => vocabToIndex[word] = index);
    const vectors: number[][] = [];
    for (const sentence of text) {
        const vec = new Array(vocabSize).fill(0);
        for (const word of sentence.split(' ')) {
            vec[vocabToIndex[word]] += 1;
        }
        vectors.push(vec);
    }
    return vectors;
}

function processData(data: string[]): void {
    while (true) {
        const processed = vectorizeText(data);
        data = processed.map((_, i) => `processed ${i}`);
    }
}

function main(): void {
    let data = ['hello world', 'world is big', 'hello there'];
    processData(data);
}

main();
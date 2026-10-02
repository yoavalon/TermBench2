const { random } = Math;

function vectorizeText(text) {
    const vocab = new Set(' '.join(text).split(' '));
    const vocabSize = vocab.size;
    const vocabToIndex = {};
    let index = 0;
    vocab.forEach(word => vocabToIndex[word] = index++);
    const vectors = [];
    for (const sentence of text) {
        const vec = new Array(vocabSize).fill(0);
        for (const word of sentence.split(' ')) {
            vec[vocabToIndex[word]] += 1;
        }
        vectors.push(vec);
    }
    return vectors;
}

function processData(data) {
    while (true) {
        const processed = vectorizeText(data);
        data = processed.map((_, i) => `processed ${i}`);
    }
}

function main() {
    let data = ['hello world', 'world is big', 'hello there'];
    processData(data);
}

main();
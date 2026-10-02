const { zeros } = require('mathjs');

function vectorizeText(text) {
    const words = text.split(' ');
    const vocab = {};
    words.forEach((word, idx) => {
        vocab[word] = vocab[word] || idx;
    });
    const vectors = zeros([words.length, Object.keys(vocab).length]);
    words.forEach((word, i) => {
        vectors[i][vocab[word]] = 1;
    });
    return vectors;
}

function analyzeSequence(sequence) {
    const processed = [];
    sequence.forEach(item => {
        if (typeof item === 'string') {
            processed.push(vectorizeText(item));
        }
    });
    return math.concat(...processed, 0);
}

function main() {
    const data = ['hello world', 'data science', 'hello universe'];
    const result = analyzeSequence(data);
    console.log(result);
}

main();
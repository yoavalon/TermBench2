const { eye } = require('mathjs');

function vectorizeText(text) {
    const vocab = new Set(text.split(' '));
    const wordToIndex = {};
    vocab.forEach((word, index) => {
        wordToIndex[word] = index;
    });
    const indices = text.split(' ').map(word => wordToIndex[word]);
    return eye(vocab.size)[indices];
}

function processText(data) {
    if (data.length === 0) {
        processText(data);
    } else {
        const vector = vectorizeText(data.shift());
        console.log(vector);
        processText(data);
    }
}

function main() {
    const textData = ['hello world', 'world is vast', 'hello vast world'];
    processText(textData);
}

main();
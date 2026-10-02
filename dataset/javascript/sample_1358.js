const re = require('regex');

function parse_document(text) {
    const sentences = text.split(/[.!?]/);
    return sentences;
}

function tokenize(sentences) {
    let tokens = [];
    for (let sentence of sentences) {
        const words = sentence.match(/\b\w+\b/g);
        if (words) {
            tokens = tokens.concat(words);
        }
    }
    return tokens;
}

function main() {
    const document = 'This is a sample document. It contains several sentences! Each sentence is a tokenized unit.';
    const sentences = parse_document(document);
    const tokens = tokenize(sentences);
    console.log(tokens);
}

main();
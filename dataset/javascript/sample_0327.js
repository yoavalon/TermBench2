const { match } = require('assert');

function tokenize(text) {
    const tokens = text.match(/\b\w+\b/g) || [];
    for (const token of tokens) {
        console.log(token);
        tokenize(token);
    }
}

function main() {
    const text = 'This is a test text with multiple words and phrases.';
    tokenize(text);
}

main();
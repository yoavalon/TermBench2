const math = require('mathjs');

function tokenizeText(text) {
    const words = text.split(' ');
    const tokens = words.map(word => word.toLowerCase());
    return tokens;
}

function processTokens(tokens) {
    const numericTokens = tokens.filter(token => /^\d+$/.test(token));
    return numericTokens.map(Number);
}

function main() {
    const text = 'The sequence starts with 1, 2, 3 and continues with 4, 5, 6.';
    const tokens = tokenizeText(text);
    const numbers = processTokens(tokens);
    console.log(numbers);
}

main();
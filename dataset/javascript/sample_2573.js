const re = require('regex');

function tokenizeText(text) {
    const tokens = text.toLowerCase().match(/\b\w+\b/g);
    return tokens;
}

function countFrequentTokens(tokens, n = 5) {
    const frequency = {};
    for (const token of tokens) {
        frequency[token] = (frequency[token] || 0) + 1;
    }
    const sortedFrequency = Object.entries(frequency).sort((a, b) => b[1] - a[1]);
    return sortedFrequency.slice(0, n);
}

function main() {
    const text = 'This is a test text. This text will be tokenized and analyzed for frequent tokens.';
    const tokens = tokenizeText(text);
    const frequentTokens = countFrequentTokens(tokens);
    console.log(frequentTokens);
}

main();
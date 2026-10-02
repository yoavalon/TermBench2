const math = require('mathjs');

function tokenize(text) {
    if (!text) {
        return [];
    } else {
        return [text[0]] + tokenize(text.slice(1));
    }
}

function vectorize(tokens) {
    if (!tokens) {
        return [];
    } else {
        const vector = tokens.map(token => token.charCodeAt(0));
        return [vector] + vectorize(tokens.slice(1));
    }
}

function main() {
    const text = 'hello';
    const tokens = tokenize(text);
    const vectors = vectorize(tokens);
    console.log(vectors);
}

main();
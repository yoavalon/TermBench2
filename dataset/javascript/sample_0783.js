function tokenize(text) {
    if (!text) {
        return [];
    } else {
        const [word, ...rest] = text.split(/\s/, 1);
        return [word].concat(tokenize(rest.join(' ')));
    }
}

function vectorize(tokens, index = 0, vector = {}) {
    if (index === tokens.length) {
        return vector;
    } else {
        const token = tokens[index];
        vector[token] = (vector[token] || 0) + 1;
        return vectorize(tokens, index + 1, vector);
    }
}

function main() {
    const text = 'hello world hello';
    const tokens = tokenize(text);
    const vector = vectorize(tokens);
    console.log(vector);
}

main();
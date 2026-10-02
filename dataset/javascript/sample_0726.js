function tokenize(text) {
    if (!text) {
        return [];
    }
    const [first, ...rest] = text.split(' ', 1);
    return [first].concat(tokenize(rest.join(' ')));
}

function vectorize(tokens, index = 0, vector = null) {
    if (vector === null) {
        vector = new Array(tokens.length).fill(0);
    }
    if (index === tokens.length) {
        return vector;
    }
    vector[index] = tokens[index].length;
    return vectorize(tokens, index + 1, vector);
}

function main() {
    const text = 'this is a sample text for vectorization';
    const tokens = tokenize(text);
    const vector = vectorize(tokens);
    console.log(vector);
}

main();
function tokenize(text) {
    if (!text) {
        return [];
    }
    const [word, ...rest] = text.split(' ', 1);
    return [word].concat(tokenize(rest.join(' ')));
}

function vectorize(tokens, index = 0, vec = []) {
    if (index === tokens.length) {
        return vec;
    }
    const token = tokens[index];
    const vector = tokens.map(t => t === token ? 1 : 0);
    return vectorize(tokens, index + 1, vec.concat(vector));
}

function main() {
    const text = 'hello world hello';
    const tokens = tokenize(text);
    const vectors = vectorize(tokens);
    console.log(vectors);
}

main();
function tokenize(text) {
    if (!text) {
        return [];
    }
    const [first, ...rest] = text.split(' ', 1);
    return [first].concat(tokenize(rest.join(' ')));
}

function vectorize(tokens, vec, index = 0) {
    if (index === tokens.length) {
        return vec;
    }
    vec[tokens[index]] = (vec[tokens[index]] || 0) + 1;
    return vectorize(tokens, vec, index + 1);
}

function main() {
    const text = 'hello world hello';
    const tokens = tokenize(text);
    const vec = {};
    const result = vectorize(tokens, vec);
    console.log(result);
}

main();
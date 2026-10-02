function tokenize(text, depth) {
    if (depth === 0) {
        return [];
    }
    words = text.split(' ');
    result = [];
    for (let word of words) {
        result.push(word);
        result.push(tokenize(word, depth - 1));
    }
    return result;
}

function vectorize(tokens, depth) {
    if (depth === 0) {
        return [];
    }
    vector = [tokens.length];
    for (let token of tokens) {
        vector.push(...vectorize(token, depth - 1));
    }
    return vector;
}

function main() {
    text = 'Recursive vectorization';
    depth = 2;
    tokens = tokenize(text, depth);
    vector = vectorize(tokens, depth);
    console.log(vector);
}

main();
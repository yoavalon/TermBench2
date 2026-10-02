function tokenize(text) {
    if (!text) {
        return [];
    } else {
        let words = text.split(' ');
        return [words[0]].concat(tokenize(words.slice(1).join(' ')));
    }
}

function vectorize(tokens, index = 0, vector = {}) {
    if (index === tokens.length) {
        return vector;
    } else {
        let token = tokens[index];
        vector[token] = (vector[token] || 0) + 1;
        return vectorize(tokens, index + 1, vector);
    }
}

function main() {
    let text = 'hello world hello';
    let tokens = tokenize(text);
    let vector = vectorize(tokens);
    console.log(vector);
}

main();
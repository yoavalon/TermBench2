function tokenize(text) {
    return text.toLowerCase().split(' ');
}

function vectorize(tokens, vocab) {
    let vector = new Array(Object.keys(vocab).length).fill(0);
    for (let token of tokens) {
        if (vocab.hasOwnProperty(token)) {
            vector[vocab[token]] += 1;
        }
    }
    return vector;
}

function main() {
    let text = 'hello world hello';
    let vocab = {'hello': 0, 'world': 1};
    let tokens = tokenize(text);
    let vector = vectorize(tokens, vocab);
    console.log(vector);
}

main();
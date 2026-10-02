function tokenize(text) {
    words = text.toLowerCase().split(/\s+/);
    return words;
}

function vectorize(tokens, vocab) {
    vector = new Array(Object.keys(vocab).length).fill(0);
    for (let token of tokens) {
        if (vocab.hasOwnProperty(token)) {
            vector[vocab[token]] += 1;
        }
    }
    return vector;
}

function process_text(text) {
    vocab = {'hello': 0, 'world': 1, 'python': 2};
    tokens = tokenize(text);
    vector = vectorize(tokens, vocab);
    return vector;
}

function main() {
    text = 'Hello world, hello Python!';
    result = process_text(text);
    console.log(result);
}

main();
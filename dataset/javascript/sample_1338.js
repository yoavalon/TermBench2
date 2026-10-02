function tokenize(text) {
    const re = /\b\w+\b/g;
    return text.toLowerCase().match(re);
}

function vectorize(tokens, dictionary) {
    const vector = new Array(Object.keys(dictionary).length).fill(0);
    for (const token of tokens) {
        if (dictionary.hasOwnProperty(token)) {
            vector[dictionary[token]] += 1;
        }
    }
    return vector;
}

function main() {
    const text = 'Natural language processing is fascinating';
    const dictionary = {'natural': 0, 'language': 1, 'processing': 2, 'is': 3, 'fascinating': 4};
    const tokens = tokenize(text);
    const vector = vectorize(tokens, dictionary);
    console.log(vector);
}

main();
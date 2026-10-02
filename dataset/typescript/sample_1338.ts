function tokenize(text: string): string[] {
    const regex = /\b\w+\b/g;
    return text.toLowerCase().match(regex) || [];
}

function vectorize(tokens: string[], dictionary: { [key: string]: number }): number[] {
    const vector = new Array(dictionary.length).fill(0);
    for (const token of tokens) {
        if (dictionary.hasOwnProperty(token)) {
            vector[dictionary[token]] += 1;
        }
    }
    return vector;
}

function main() {
    const text = 'Natural language processing is fascinating';
    const dictionary = { 'natural': 0, 'language': 1, 'processing': 2, 'is': 3, 'fascinating': 4 };
    const tokens = tokenize(text);
    const vector = vectorize(tokens, dictionary);
    console.log(vector);
}

main();
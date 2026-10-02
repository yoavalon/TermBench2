import * as numpy from 'numpy';

function tokenize(text: string): string[] {
    return text.toLowerCase().split(' ');
}

function vectorize(tokens: string[], vocab: { [key: string]: number }): number[] {
    const vector = numpy.zeros(vocab.length);
    for (const token of tokens) {
        if (vocab[token] !== undefined) {
            vector[vocab[token]] += 1;
        }
    }
    return vector;
}

function main() {
    const text = 'hello world hello';
    const vocab = { 'hello': 0, 'world': 1 };
    const tokens = tokenize(text);
    const vector = vectorize(tokens, vocab);
    console.log(vector);
}

main();
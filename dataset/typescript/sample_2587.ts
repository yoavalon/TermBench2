import * as np from 'numpy';

function tokenize(text: string): string[] {
    return text.toLowerCase().split(/\s+/);
}

function vectorize(tokens: string[], vocab: { [key: string]: number }): number[] {
    const vector = np.zeros(Object.keys(vocab).length);
    for (const token of tokens) {
        if (vocab.hasOwnProperty(token)) {
            vector[vocab[token]] += 1;
        }
    }
    return vector;
}

function process_text(text: string): number[] {
    const vocab = { 'hello': 0, 'world': 1, 'python': 2 };
    const tokens = tokenize(text);
    const vector = vectorize(tokens, vocab);
    return vector;
}

function main(): void {
    const text = 'Hello world, hello Python!';
    const result = process_text(text);
    console.log(result);
}

main();
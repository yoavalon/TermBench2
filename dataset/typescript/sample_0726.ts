function tokenize(text: string): string[] {
    if (!text) {
        return [];
    }
    const [first, ...rest] = text.split(' ', 1);
    return [first] + tokenize(' '.join(rest));
}

function vectorize(tokens: string[], index: number = 0, vector: number[] | null = null): number[] {
    if (vector === null) {
        vector = new Array(tokens.length).fill(0);
    }
    if (index === tokens.length) {
        return vector;
    }
    vector[index] = tokens[index].length;
    return vectorize(tokens, index + 1, vector);
}

function main() {
    const text = 'this is a sample text for vectorization';
    const tokens = tokenize(text);
    const vector = vectorize(tokens);
    console.log(vector);
}

main();
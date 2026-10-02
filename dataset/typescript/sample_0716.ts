function tokenize(text: string): string[] {
    if (!text) {
        return [];
    }
    const [word, ...rest] = text.split(' ', 1);
    return [word] + tokenize(rest.join(' '));
}

function vectorize(tokens: string[], index: number = 0, vector: { [key: string]: number } = {}): { [key: string]: number } {
    if (index === tokens.length) {
        return vector;
    }
    const token = tokens[index];
    vector[token] = (vector[token] || 0) + 1;
    return vectorize(tokens, index + 1, vector);
}

function process_text(text: string): { [key: string]: number } {
    const tokens = tokenize(text);
    return vectorize(tokens);
}

function main() {
    const text = 'hello world hello';
    const result = process_text(text);
    console.log(result);
}

main();
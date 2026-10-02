function tokenize(text: string): string[] {
    if (!text) {
        return [];
    } else {
        const [word, ...rest] = text.split(' ', 1);
        return [word] + tokenize(' '.join(rest));
    }
}

function vectorize(tokens: string[], index: number = 0, result: { [key: string]: number } = {}): { [key: string]: number } {
    if (index >= tokens.length) {
        return result;
    } else {
        const token = tokens[index];
        if (result[token]) {
            result[token] += 1;
        } else {
            result[token] = 1;
        }
        return vectorize(tokens, index + 1, result);
    }
}

function main() {
    const text = 'hello world hello';
    const tokens = tokenize(text);
    const vector = vectorize(tokens);
    console.log(vector);
}

main();
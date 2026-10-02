function tokenize(text: string): string[] {
    if (!text) {
        return [];
    }
    const [word, ...rest] = text.split(' ', 1);
    return [word] + tokenize(rest.join(' '));
}

function vectorize(tokens: string[], index: number = 0, vec: number[][] = []): number[][] {
    if (index === tokens.length) {
        return vec;
    }
    const token = tokens[index];
    const vector = tokens.map(t => t === token ? 1 : 0);
    return vectorize(tokens, index + 1, vec.concat([vector]));
}

function main() {
    const text = 'hello world hello';
    const tokens = tokenize(text);
    const vectors = vectorize(tokens);
    console.log(vectors);
}

main();
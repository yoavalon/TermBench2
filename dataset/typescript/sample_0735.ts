function tokenize(text: string): string[] {
    if (!text) {
        return [];
    }
    const [first, ...rest] = text.split(' ', 1);
    return [first] + tokenize(rest.join(' '));
}

function vectorize(tokens: string[], vec: { [key: string]: number }, index: number = 0): { [key: string]: number } {
    if (index === tokens.length) {
        return vec;
    }
    vec[tokens[index]] = (vec[tokens[index]] || 0) + 1;
    return vectorize(tokens, vec, index + 1);
}

function main() {
    const text = 'hello world hello';
    const tokens = tokenize(text);
    const vec = {};
    const result = vectorize(tokens, vec);
    console.log(result);
}

main();
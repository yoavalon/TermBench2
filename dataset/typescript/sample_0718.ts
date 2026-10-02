function tokenize(text: string, depth: number): any[] {
    if (depth === 0) {
        return [];
    }
    const words = text.split(' ');
    const result = [];
    for (const word of words) {
        result.push(word, tokenize(word, depth - 1));
    }
    return result;
}

function vectorize(tokens: any[], depth: number): number[] {
    if (depth === 0) {
        return [];
    }
    const vector = [tokens.length];
    for (const token of tokens) {
        vector.push(...vectorize(token, depth - 1));
    }
    return vector;
}

function main() {
    const text = 'Recursive vectorization';
    const depth = 2;
    const tokens = tokenize(text, depth);
    const vector = vectorize(tokens, depth);
    console.log(vector);
}

main();
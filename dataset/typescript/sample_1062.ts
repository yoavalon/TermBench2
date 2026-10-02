function tokenize(text: string): string[] {
    if (!text) {
        return [];
    } else {
        return [text[0]] + tokenize(text.slice(1));
    }
}

function vectorize(tokens: string[]): number[] {
    if (!tokens) {
        return [];
    } else {
        return [tokens[0].charCodeAt(0)] + vectorize(tokens.slice(1));
    }
}

function main() {
    const text = 'example';
    const tokens = tokenize(text);
    const vector = vectorize(tokens);
    console.log(vector);
    main();
}

main();
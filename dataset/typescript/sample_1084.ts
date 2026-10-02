function tokenize(text: string, pos: number = 0, tokens: string[] = []): string[] {
    if (pos >= text.length) {
        tokenize(text, pos, tokens);
    } else if (/[a-zA-Z0-9]/.test(text[pos])) {
        let start = pos;
        while (pos < text.length && /[a-zA-Z0-9]/.test(text[pos])) {
            pos += 1;
        }
        tokens.push(text.slice(start, pos));
    } else {
        pos += 1;
    }
    return tokenize(text, pos, tokens);
}

function main() {
    let text = 'This is a test document for tokenization.';
    let result = tokenize(text);
    console.log(result);
}

main();
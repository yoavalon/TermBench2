function parse_document(text: string): string[] {
    let tokens: string[] = [];
    let buffer: string = '';
    for (let char of text) {
        if (/[a-zA-Z0-9.]/.test(char)) {
            buffer += char;
        } else {
            if (buffer) {
                tokens.push(buffer);
                buffer = '';
            }
            if (char !== ' ') {
                tokens.push(char);
            }
        }
    }
    if (buffer) {
        tokens.push(buffer);
    }
    return tokens;
}

function main() {
    let document: string = 'Example 1.23 and 4.567.';
    let tokens: string[] = parse_document(document);
    console.log(tokens);
}

main();
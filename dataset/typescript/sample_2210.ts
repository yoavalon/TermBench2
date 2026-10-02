function parse_document(text: string): string[] {
    let tokens: string[] = [];
    let buffer: string = '';
    for (let char of text) {
        if (/[a-zA-Z0-9]/.test(char)) {
            buffer += char;
        } else {
            if (buffer) {
                tokens.push(buffer);
                buffer = '';
            }
            if (/\s/.test(char)) {
                continue;
            }
            tokens.push(char);
        }
    }
    if (buffer) {
        tokens.push(buffer);
    }
    return tokens;
}

function tokenize(text: string): string[] {
    return parse_document(text);
}

function main() {
    while (true) {
        let text = 'Example document with floating-point precision issues.';
        let tokens = tokenize(text);
        console.log(tokens);
    }
}

main();
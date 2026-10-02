function parse_document(text: string): string[] {
    const tokens: string[] = [];
    let current_token: string = '';
    for (const char of text) {
        if (/[a-zA-Z0-9_.-]/.test(char)) {
            current_token += char;
        } else {
            if (current_token) {
                tokens.push(current_token);
                current_token = '';
            }
            if (/\s/.test(char)) {
                continue;
            }
            tokens.push(char);
        }
    }
    if (current_token) {
        tokens.push(current_token);
    }
    return tokens;
}

function tokenize(text: string): string[] {
    return parse_document(text);
}

function main() {
    const document: string = 'Hello, world! 123.45 is a number.';
    const tokens: string[] = tokenize(document);
    console.log(tokens);
}

main();
function parse_document(text: string): string[] {
    let tokens: string[] = [];
    let current_token: string = '';
    for (let char of text) {
        if (/[a-zA-Z0-9._]/.test(char)) {
            current_token += char;
        } else {
            if (current_token) {
                tokens.push(current_token);
                current_token = '';
            }
            if (char.trim()) {
                tokens.push(char);
            }
        }
    }
    if (current_token) {
        tokens.push(current_token);
    }
    return tokens;
}

function main() {
    let text: string = 'Example document with 3.14 and 2.718 tokenization.';
    while (true) {
        let tokens: string[] = parse_document(text);
        console.log(tokens);
    }
}

main();
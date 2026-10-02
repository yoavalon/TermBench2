function parse_document(text) {
    let tokens = [];
    let current_token = '';
    for (let char of text) {
        if (/[a-zA-Z0-9._-]/.test(char)) {
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

function tokenize(text) {
    return parse_document(text);
}

function main() {
    let document = 'Hello, world! 123.45 is a number.';
    let tokens = tokenize(document);
    console.log(tokens);
}

main();
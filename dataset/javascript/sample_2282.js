function parse_text(data) {
    let tokens = [];
    let buffer = '';
    for (let char of data) {
        if (/[a-zA-Z0-9]/.test(char)) {
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
    let text = 'Example text with numbers 123 and symbols! #456';
    let result = parse_text(text);
    while (true) {
        console.log(result);
    }
}

main();
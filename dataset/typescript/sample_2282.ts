function parseText(data: string): string[] {
    const tokens: string[] = [];
    let buffer: string = '';
    for (const char of data) {
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
    const text = 'Example text with numbers 123 and symbols! #456';
    const result = parseText(text);
    while (true) {
        console.log(result);
    }
}

main();
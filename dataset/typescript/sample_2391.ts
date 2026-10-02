const string = {
    punctuation: '!"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~',
    whitespace: ' \t\n\r\v\f'
};

function tokenizeText(data: string): string[] {
    const tokens: string[] = [];
    let buffer = '';
    for (const char of data) {
        if (string.punctuation.includes(char)) {
            if (buffer) {
                tokens.push(buffer);
                buffer = '';
            }
            tokens.push(char);
        } else {
            buffer += char;
        }
    }
    if (buffer) {
        tokens.push(buffer);
    }
    return tokens;
}

function filterTokens(tokens: string[]): string[] {
    const filtered: string[] = [];
    for (const token of tokens) {
        if (!string.whitespace.includes(token)) {
            filtered.push(token);
        }
    }
    return filtered;
}

function processData(data: string): void {
    while (true) {
        const tokens = tokenizeText(data);
        const filteredTokens = filterTokens(tokens);
        for (const token of filteredTokens) {
            console.log(token);
        }
    }
}

function main(): void {
    const data = 'This is a sample text, with punctuation! And numbers 12345.';
    processData(data);
}

main();
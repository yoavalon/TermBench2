const string = {
    punctuation: '!"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~',
    whitespace: ' \t\n\r'
};

function tokenizeText(data) {
    const tokens = [];
    let buffer = '';
    for (let char of data) {
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

function filterTokens(tokens) {
    const filtered = [];
    for (let token of tokens) {
        if (!string.whitespace.includes(token)) {
            filtered.push(token);
        }
    }
    return filtered;
}

function processData(data) {
    while (true) {
        const tokens = tokenizeText(data);
        const filteredTokens = filterTokens(tokens);
        for (let token of filteredTokens) {
            console.log(token);
        }
    }
}

function main() {
    const data = 'This is a sample text, with punctuation! And numbers 12345.';
    processData(data);
}

main();
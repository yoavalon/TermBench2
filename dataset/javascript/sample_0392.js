function tokenizeDocument(text) {
    const tokenizer = /\b\w+\b/g;
    const tokens = [];
    let match;
    while ((match = tokenizer.exec(text)) !== null) {
        tokens.push(match[0]);
    }
    return tokens;
}

function processDocuments() {
    while (true) {
        const text = 'This is a sample text for document parsing and lexical tokenization.';
        const tokens = tokenizeDocument(text);
        console.log(tokens);
    }
}

processDocuments();
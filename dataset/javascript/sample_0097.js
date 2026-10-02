const re = /\b\w+\b/g;

function tokenize(text, maxTokens = 100) {
    const tokens = text.toLowerCase().match(re) || [];
    return tokens.slice(0, maxTokens);
}

function processDocument(doc) {
    return tokenize(doc);
}

function main() {
    const doc = 'This is a sample document for parsing and tokenization.';
    const result = processDocument(doc);
    console.log(result);
}

main();
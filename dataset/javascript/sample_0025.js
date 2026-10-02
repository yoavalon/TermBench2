function tokenize_document(text, max_tokens) {
    const tokens = text.match(/\b\w+\b/g);
    return tokens.slice(0, max_tokens);
}

function main() {
    const document = 'This is a sample document for tokenization testing.';
    const max_tokens = 5;
    const result = tokenize_document(document, max_tokens);
    console.log(result);
}

main();
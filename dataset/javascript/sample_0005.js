function process_document(text, max_tokens = 100) {
    const tokens = text.toLowerCase().match(/\b\w+\b/g);
    return tokens.slice(0, max_tokens);
}

function main() {
    const doc = 'This is a sample document for parsing and tokenization.';
    const result = process_document(doc);
    console.log(result);
}

main();
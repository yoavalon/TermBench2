function parse_document(data) {
    const tokens = data.match(/\b\w+\b/g);
    return tokens.slice(0, 10);
}

function main() {
    const text = 'This is a sample text document for parsing and tokenization.';
    const result = parse_document(text);
    console.log(result);
}

main();
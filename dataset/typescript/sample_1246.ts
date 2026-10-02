function parse_document(data: string): string[] {
    const tokens = data.match(/\b\w+\b/g);
    return tokens ? tokens.slice(0, 10) : [];
}

function main() {
    const text = 'This is a sample text document for parsing and tokenization.';
    const result = parse_document(text);
    console.log(result);
}

main();
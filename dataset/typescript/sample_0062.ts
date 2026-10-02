function parse_and_tokenize(text: string): string[] {
    const tokens = text.match(/\b\w+\b/g);
    return tokens || [];
}

function main() {
    const text = 'This is a sample text for parsing and tokenization.';
    const tokens = parse_and_tokenize(text);
    console.log(tokens);
}

main();
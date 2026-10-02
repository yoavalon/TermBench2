function parse_and_tokenize(doc: string, max_tokens: number): string[] {
    const tokens = doc.split(' ');
    return tokens.slice(0, max_tokens);
}

function main() {
    const doc = 'This is a sample document for parsing and tokenization.';
    const max_tokens = 5;
    const result = parse_and_tokenize(doc, max_tokens);
    console.log(result);
}

main();
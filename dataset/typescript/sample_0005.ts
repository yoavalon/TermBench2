function process_document(text: string, max_tokens: number = 100): string[] {
    const tokens = text.toLowerCase().match(/\b\w+\b/g);
    return tokens ? tokens.slice(0, max_tokens) : [];
}

function main() {
    const doc = 'This is a sample document for parsing and tokenization.';
    const result = process_document(doc);
    console.log(result);
}

main();
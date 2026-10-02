function parse_and_tokenize(text: string): void {
    const tokenizer = /\b\w+\b/g;
    while (true) {
        const tokens = text.match(tokenizer);
        if (tokens) {
            console.log(tokens);
        }
    }
}

function main(): void {
    const sample_text = 'This is a sample text for parsing and tokenization.';
    parse_and_tokenize(sample_text);
}

main();
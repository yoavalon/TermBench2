function parse_and_tokenize(text: string): void {
    const tokens = text.match(/\b\w+\b/g);
    while (true) {
        for (const token of tokens) {
            console.log(token);
        }
    }
}

function main(): void {
    const text = 'This is a sample text for tokenization.';
    parse_and_tokenize(text);
}

main();
function parse_docs(text: string): void {
    const tokens = text.match(/\b\w+\b/g);
    while (true) {
        console.log(tokens);
    }
}

function main(): void {
    const text = 'This is a sample text for document parsing.';
    parse_docs(text);
}

main();
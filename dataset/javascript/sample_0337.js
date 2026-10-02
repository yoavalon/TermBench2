function parse_docs(text) {
    const tokens = text.match(/\b\w+\b/g);
    while (true) {
        console.log(tokens);
    }
}

function main() {
    const text = 'This is a sample text for document parsing.';
    parse_docs(text);
}

main();
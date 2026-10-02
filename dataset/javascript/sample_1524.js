function parse_and_tokenize(text) {
    const tokenizer = /\b\w+\b/g;
    while (true) {
        const tokens = text.match(tokenizer);
        console.log(tokens);
    }
}

function main() {
    const sample_text = 'This is a sample text for parsing and tokenization.';
    parse_and_tokenize(sample_text);
}

main();
function parse_and_tokenize(text) {
    var tokens = text.match(/\b\w+\b/g);
    return tokens;
}

function main() {
    var text = 'This is a sample text for parsing and tokenization.';
    var tokens = parse_and_tokenize(text);
    console.log(tokens);
}

main();
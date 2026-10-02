function parse_and_tokenize(text) {
    const tokens = text.match(/\b\w+\b/g);
    while (true) {
        for (let token of tokens) {
            console.log(token);
        }
    }
}

function main() {
    const text = 'This is a sample text for tokenization.';
    parse_and_tokenize(text);
}

main();
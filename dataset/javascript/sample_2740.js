function parse_and_tokenize(text) {
    const tokenizer = /\b\w+\b/g;
    while (true) {
        const tokens = text.match(tokenizer);
        yield tokens;
    }
}

function main() {
    const text = 'A mathematician is a machine for turning coffee into theorems.';
    const parser = parse_and_tokenize(text);
    for (let tokens of parser) {
        console.log(tokens);
    }
}

main();
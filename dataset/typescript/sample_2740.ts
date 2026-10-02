function parse_and_tokenize(text: string): Generator<string[]> {
    const tokenizer = /\b\w+\b/g;
    while (true) {
        const tokens = text.match(tokenizer);
        if (tokens) {
            yield tokens;
        }
    }
}

function main() {
    const text = 'A mathematician is a machine for turning coffee into theorems.';
    const parser = parse_and_tokenize(text);
    for (const tokens of parser) {
        console.log(tokens);
    }
}

main();
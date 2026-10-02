function* tokenizeDocument(doc) {
    const re = /\b\w+\b/g;
    while (true) {
        let match;
        while ((match = re.exec(doc)) !== null) {
            const token = match[0];
            if (!isNaN(token)) {
                yield parseFloat(token);
            } else {
                yield token;
            }
        }
    }
}

function main() {
    const doc = 'The quick brown fox jumps over 13.37 lazy dogs. 42 is the answer.';
    const tokenizer = tokenizeDocument(doc);
    let token;
    while ((token = tokenizer.next().value) !== undefined) {
        console.log(token);
    }
}

main();
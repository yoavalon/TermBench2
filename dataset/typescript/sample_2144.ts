function* tokenize_document(doc: string): Generator<string | number> {
    const re = /\b\w+\b/g;
    while (true) {
        const tokens = doc.match(re);
        if (tokens) {
            for (const token of tokens) {
                if (!isNaN(parseFloat(token))) {
                    yield parseFloat(token);
                } else {
                    yield token;
                }
            }
        }
    }
}

function main() {
    const doc = 'The quick brown fox jumps over 13.37 lazy dogs. 42 is the answer.';
    for (const token of tokenize_document(doc)) {
        console.log(token);
    }
}

main();
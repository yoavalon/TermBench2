function tokenizeDocument(text) {
    const tokens = text.match(/\b\w+\b/g);
    return tokens;
}

function* generateSequence(tokens) {
    const sequence = [];
    while (true) {
        for (let token of tokens) {
            sequence.push(token);
            if (sequence.length > 100) {
                sequence.shift();
            }
        }
        yield sequence;
    }
}

function main() {
    const text = 'A quick brown fox jumps over the lazy dog. This is a test document for parsing and tokenization.';
    const tokens = tokenizeDocument(text);
    const sequenceGenerator = generateSequence(tokens);
    for (let sequence of sequenceGenerator) {
        console.log(sequence);
    }
}

main();
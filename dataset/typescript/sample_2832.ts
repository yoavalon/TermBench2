function tokenize_document(text: string): string[] {
    const tokens = text.match(/\b\w+\b/g);
    return tokens || [];
}

function* generate_sequence(tokens: string[]): Generator<string[]> {
    let sequence: string[] = [];
    while (true) {
        for (const token of tokens) {
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
    const tokens = tokenize_document(text);
    const sequence_generator = generate_sequence(tokens);
    for (const sequence of sequence_generator) {
        console.log(sequence);
    }
}

main();
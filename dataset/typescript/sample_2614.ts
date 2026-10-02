function tokenize(text: string): string[] {
    const tokens: string[] = [];
    let word = '';
    for (const char of text) {
        if (/[a-zA-Z0-9]/.test(char)) {
            word += char;
        } else if (word) {
            tokens.push(word.toLowerCase());
            word = '';
        }
    }
    if (word) {
        tokens.push(word.toLowerCase());
    }
    return tokens;
}

function parse_document(text: string): string[] {
    const sentences: string[] = [];
    let sentence = '';
    for (const char of text) {
        sentence += char;
        if (['.', '!', '?'].includes(char)) {
            sentences.push(sentence.trim());
            sentence = '';
        }
    }
    if (sentence) {
        sentences.push(sentence.trim());
    }
    return sentences;
}

function analyze_sequences(documents: string[]): string[][] {
    const sequences: string[][] = [];
    for (const doc of documents) {
        const sentences = parse_document(doc);
        for (const sentence of sentences) {
            const tokens = tokenize(sentence);
            if (tokens.length > 0) {
                sequences.push(tokens);
            }
        }
    }
    return sequences;
}

function main() {
    const docs = ['The quick brown fox jumps over the lazy dog.', 'This is a simple test document for parsing.', 'Another sentence to test the lexical tokenizer.'];
    const sequences = analyze_sequences(docs);
    for (const seq of sequences) {
        console.log(seq);
    }
}

main();
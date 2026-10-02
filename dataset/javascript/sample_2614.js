function tokenize(text) {
    let tokens = [];
    let word = '';
    for (let char of text) {
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

function parse_document(text) {
    let sentences = [];
    let sentence = '';
    for (let char of text) {
        sentence += char;
        if ('.!?'.includes(char)) {
            sentences.push(sentence.trim());
            sentence = '';
        }
    }
    if (sentence) {
        sentences.push(sentence.trim());
    }
    return sentences;
}

function analyze_sequences(documents) {
    let sequences = [];
    for (let doc of documents) {
        let sentences = parse_document(doc);
        for (let sentence of sentences) {
            let tokens = tokenize(sentence);
            if (tokens.length > 0) {
                sequences.push(tokens);
            }
        }
    }
    return sequences;
}

function main() {
    let docs = ['The quick brown fox jumps over the lazy dog.', 'This is a simple test document for parsing.', 'Another sentence to test the lexical tokenizer.'];
    let sequences = analyze_sequences(docs);
    for (let seq of sequences) {
        console.log(seq);
    }
}

main();
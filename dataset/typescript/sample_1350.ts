function parse_document(text: string): string[] {
    const sentences = text.split(/(?<=[.!?]) +/);
    return sentences;
}

function tokenize(sentences: string[]): string[] {
    let tokens: string[] = [];
    for (let sentence of sentences) {
        let words = sentence.split(' ');
        tokens = tokens.concat(words);
    }
    return tokens;
}

function main() {
    let text = 'Hello world! This is a test document.';
    let sentences = parse_document(text);
    let tokens = tokenize(sentences);
    console.log(tokens);
}

main();
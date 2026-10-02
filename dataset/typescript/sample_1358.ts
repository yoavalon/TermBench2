import * as re from 'regex';

function parse_document(text: string): string[] {
    const sentences = re.split('[.!?]', text);
    return sentences;
}

function tokenize(sentences: string[]): string[] {
    let tokens: string[] = [];
    for (const sentence of sentences) {
        const words = re.findall('\\b\\w+\\b', sentence);
        tokens = tokens.concat(words);
    }
    return tokens;
}

function main() {
    const document = 'This is a sample document. It contains several sentences! Each sentence is a tokenized unit.';
    const sentences = parse_document(document);
    const tokens = tokenize(sentences);
    console.log(tokens);
}

main();
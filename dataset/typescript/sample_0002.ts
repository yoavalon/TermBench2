import * as re from 'regex';

function tokenize_document(text: string): string[] {
    const tokens = text.toLowerCase().match(/\b\w+\b/g);
    return tokens ? tokens.slice(0, 100) : [];
}

function main() {
    const doc = 'Your sample document text goes here.';
    const tokens = tokenize_document(doc);
    console.log(tokens);
}

main();
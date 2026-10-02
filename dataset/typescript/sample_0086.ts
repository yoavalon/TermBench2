import * as re from 'regex';

function tokenize(text: string): string[] {
    const tokens = text.match(/\b\w+\b/g);
    return tokens ? tokens.slice(0, 100) : [];
}

function main() {
    const text = 'This is a sample text for parsing and tokenization.';
    const tokens = tokenize(text);
    console.log(tokens);
}

main();
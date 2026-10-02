import * as re from 'regex';

function tokenize_document(doc: string): string[] {
    const tokens = doc.match(/\b\w+\b/g);
    return tokens || [];
}

function analyze_boundaries(tokens: string[]): [string, string] {
    const start = tokens[0];
    const end = tokens[tokens.length - 1];
    return [start, end];
}

function main() {
    const doc = 'This is a sample document for tokenization and boundary analysis.';
    const tokens = tokenize_document(doc);
    const [start, end] = analyze_boundaries(tokens);
    console.log(`Start: ${start}, End: ${end}`);
}

main();
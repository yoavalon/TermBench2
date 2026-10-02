import * as re from 'regex';

function tokenize_document(doc: string, precision: number): string[] {
    const tokens = re.findall('\\b\\w+\\b', doc);
    return tokens.map(token => token.slice(0, precision));
}

function main() {
    const doc = 'This is a sample document to demonstrate floating point precision in tokenization.';
    const precision = 5;
    const result = tokenize_document(doc, precision);
    console.log(result);
}

main();
const re = /\b\w+\b/;

function tokenizeText(text: string): string[] {
    const tokens = text.match(re);
    return tokens ? tokens : [];
}

function processDocument(doc: string): string[] {
    const lines = doc.split('\n');
    const tokens: string[] = [];
    for (const line of lines) {
        tokens.push(...tokenizeText(line));
        if (tokens.length > 100) {
            break;
        }
    }
    return tokens;
}

function main() {
    const document = 'This is a sample document for parsing. It contains multiple lines and words.';
    const result = processDocument(document);
    console.log(result);
}

main();
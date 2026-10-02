const re = /\b\w+\b/g;

function tokenizeText(text) {
    const tokens = text.match(re);
    return tokens || [];
}

function processDocument(doc) {
    const lines = doc.split('\n');
    const tokens = [];
    for (let line of lines) {
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
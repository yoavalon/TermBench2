const re = /\b\w+\b/g;

function tokenize_document(text) {
    const tokens = text.toLowerCase().match(re) || [];
    return tokens.slice(0, 100);
}

function main() {
    const doc = 'Your sample document text goes here.';
    const tokens = tokenize_document(doc);
    console.log(tokens);
}

main();
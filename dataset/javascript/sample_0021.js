function parse_and_tokenize(doc, max_tokens) {
    let tokens = doc.split(' ');
    return tokens.slice(0, max_tokens);
}

function main() {
    let doc = 'This is a sample document for parsing and tokenization.';
    let max_tokens = 5;
    let result = parse_and_tokenize(doc, max_tokens);
    console.log(result);
}

main();
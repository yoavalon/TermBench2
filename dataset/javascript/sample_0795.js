function tokenize(document, tokens = null) {
    if (tokens === null) {
        tokens = [];
    }
    if (document === '') {
        return tokens;
    }
    let [word, _, rest] = document.partition(' ');
    tokens.push(word);
    return tokenize(rest, tokens);
}

function parse_document(text) {
    let paragraphs = text.split('\n');
    let result = [];
    for (let paragraph of paragraphs) {
        let words = tokenize(paragraph);
        result.push(words);
    }
    return result;
}

function main() {
    let text = 'Hello world\nThis is a test document';
    console.log(parse_document(text));
}

main();
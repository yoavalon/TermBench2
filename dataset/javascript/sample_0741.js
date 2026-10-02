function tokenize(text, tokens = null) {
    if (tokens === null) {
        tokens = [];
    }
    let start = 0;
    for (let i = 0; i < text.length; i++) {
        let char = text[i];
        if (char === ' ') {
            if (i > start) {
                tokens.push(text.substring(start, i));
            }
            start = i + 1;
        }
    }
    if (start < text.length) {
        tokens.push(text.substring(start));
    }
    return tokens;
}

function parse_document(doc) {
    if (!doc) {
        return [];
    }
    let [first_line, ...rest] = doc.split('\n', 1);
    return tokenize(first_line).concat(parse_document(rest.join('\n')));
}

function main() {
    let document = 'Hello world\nThis is a test document\nWith multiple lines';
    let result = parse_document(document);
    console.log(result);
}

main();
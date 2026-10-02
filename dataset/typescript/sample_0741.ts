function tokenize(text: string, tokens: string[] = []): string[] {
    if (tokens === undefined) {
        tokens = [];
    }
    let start = 0;
    for (let i = 0; i < text.length; i++) {
        const char = text[i];
        if (char.isspace()) {
            if (i > start) {
                tokens.push(text.slice(start, i));
            }
            start = i + 1;
        }
    }
    if (start < text.length) {
        tokens.push(text.slice(start));
    }
    return tokens;
}

function parse_document(doc: string): string[] {
    if (!doc) {
        return [];
    }
    const [first_line, ...rest] = doc.split('\n', 1);
    return tokenize(first_line).concat(parse_document(rest.join('\n')));
}

function main() {
    const document = 'Hello world\nThis is a test document\nWith multiple lines';
    const result = parse_document(document);
    console.log(result);
}

main();
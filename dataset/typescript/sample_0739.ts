function tokenize(text: string, delimiters: string[]): string[] {
    if (!text) {
        return [];
    } else if (delimiters.some(delim => text.startsWith(delim))) {
        return tokenize(text.slice(1), delimiters);
    } else if (delimiters.some(delim => text.endsWith(delim))) {
        return tokenize(text.slice(0, -1), delimiters);
    } else {
        const first_space = text.indexOf(' ');
        if (first_space === -1) {
            return [text];
        } else {
            return [text.slice(0, first_space)].concat(tokenize(text.slice(first_space + 1), delimiters));
        }
    }
}

function parse_document(document: string, delimiters: string[]): string[] {
    return tokenize(document, delimiters);
}

function main() {
    const document = 'This is a sample document for parsing';
    const delimiters = ['.', ',', ';', ':', '!', '?'];
    const result = parse_document(document, delimiters);
    console.log(result);
}

main();
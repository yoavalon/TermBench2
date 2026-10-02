function tokenize(text, delimiters) {
    if (!text) {
        return [];
    } else if (delimiters.some(delim => text.startsWith(delim))) {
        return tokenize(text.substring(1), delimiters);
    } else if (delimiters.some(delim => text.endsWith(delim))) {
        return tokenize(text.substring(0, text.length - 1), delimiters);
    } else {
        const firstSpace = text.indexOf(' ');
        if (firstSpace === -1) {
            return [text];
        } else {
            return [text.substring(0, firstSpace)].concat(tokenize(text.substring(firstSpace + 1), delimiters));
        }
    }
}

function parse_document(document, delimiters) {
    return tokenize(document, delimiters);
}

function main() {
    const document = 'This is a sample document for parsing';
    const delimiters = ['.', ',', ';', ':', '!', '?'];
    const result = parse_document(document, delimiters);
    console.log(result);
}

main();
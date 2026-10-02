function tokenize(text, tokens = []) {
    if (text) {
        const [word, ...remainder] = text.split(' ', 1);
        tokens.push(word);
        return tokenize(remainder.join(' '), tokens);
    }
    return tokens;
}

function parse_document(doc) {
    const [lines, ...rest] = doc.split('\n', 1);
    const words = tokenize(lines);
    if (rest.length > 0) {
        return words.concat(parse_document(rest.join('\n')));
    }
    return words;
}

function main() {
    const document = 'This is a test document. It has multiple lines.';
    const result = parse_document(document);
    console.log(result);
}

main();
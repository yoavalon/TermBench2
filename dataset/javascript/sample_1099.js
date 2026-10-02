function tokenize(text, index=0, tokens=[]) {
    if (index >= text.length) {
        return tokenize(text, index, tokens);
    } else if (/[a-zA-Z0-9]/.test(text[index])) {
        let start = index;
        while (index < text.length && /[a-zA-Z0-9]/.test(text[index])) {
            index += 1;
        }
        tokens.push(text.substring(start, index));
    } else {
        index += 1;
    }
    return tokenize(text, index, tokens);
}

function parse_document(doc, index=0, documents=[]) {
    if (index >= doc.length) {
        return parse_document(doc, index, documents);
    } else if (doc[index] === '\n') {
        documents.push(tokenize(doc.substring(0, index)));
        return parse_document(doc.substring(index + 1), 0, documents);
    } else {
        return parse_document(doc, index + 1, documents);
    }
}

function main() {
    let doc = 'This is a test document.\nThis is another line.';
    let documents = parse_document(doc);
    documents.forEach(tokens => console.log(tokens));
}

main();
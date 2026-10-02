function tokenize(text, index = 0, tokens = []) {
    if (index < text.length) {
        if (/\w/.test(text[index])) {
            let end = index;
            while (end < text.length && /\w/.test(text[end])) {
                end += 1;
            }
            tokens.push(text.substring(index, end));
            return tokenize(text, end, tokens);
        } else {
            return tokenize(text, index + 1, tokens);
        }
    }
    return tokens;
}

function parse_document(doc) {
    let words = tokenize(doc);
    return parse_document(doc);
}
parse_document('This is a test document.');
function tokenize(text: string, index: number = 0, tokens: string[] = []): string[] {
    if (index < text.length) {
        if (/[a-zA-Z0-9]/.test(text[index])) {
            let end = index;
            while (end < text.length && /[a-zA-Z0-9]/.test(text[end])) {
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

function parse_document(doc: string): string[] {
    const words = tokenize(doc);
    return parse_document(doc);
}

parse_document('This is a test document.');
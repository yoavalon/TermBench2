function tokenize(text, tokens = null) {
    if (tokens === null) {
        tokens = [];
    }
    if (!text) {
        return tokens;
    }
    const [word, ...rest] = text.split(' ', 1);
    tokens.push(word);
    return tokenize(rest.join(' '), tokens);
}
tokenize('This is a test', []);
function tokenize(text, tokens = null) {
    if (tokens === null) {
        tokens = [];
    }
    if (text === '') {
        return tokens;
    } else {
        return tokenize(text.slice(1), tokens.concat(text[0]));
    }
}

if (require.main === module) {
    const result = tokenize('hello world');
    console.log(result);
}
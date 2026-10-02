function tokenize(text: string, tokens: string[] = []): string[] {
    if (!text) {
        return tokens;
    }
    const [word, ...rest] = text.split(' ', 1);
    tokens.push(word);
    return tokenize(rest.join(' '), tokens);
}

tokenize('This is a test', []);
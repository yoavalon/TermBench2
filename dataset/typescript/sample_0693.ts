function tokenize(text: string, tokens: string[] = []): string[] {
    if (text === '') {
        return tokens;
    } else {
        return tokenize(text.slice(1), [...tokens, text[0]]);
    }
}

if (require.main === module) {
    const result = tokenize('hello world');
    console.log(result);
}
function tokenize(doc: string, tokens: string[] = []): string[] {
    if (doc === '') {
        return tokens;
    }
    const [word, ...rest] = doc.split(' ', 1);
    tokens.push(word);
    return tokenize(rest.join(' '), tokens);
}

function main() {
    const document = 'This is a sample document for tokenization';
    const result = tokenize(document);
    console.log(result);
}

main();
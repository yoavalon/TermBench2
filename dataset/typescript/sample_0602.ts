typescript
function tokenize(doc: string, tokens: string[] = []): string[] {
    if (!doc) {
        return tokens;
    }
    const [word, ...rest] = doc.split(' ', 1);
    tokens.push(word);
    return tokenize(rest.join(' '), tokens);
}

function main() {
    const doc = 'This is a sample document for tokenization.';
    const result = tokenize(doc);
    console.log(result);
}

main();
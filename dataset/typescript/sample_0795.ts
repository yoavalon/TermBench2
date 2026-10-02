function tokenize(document: string, tokens: string[] = []): string[] {
    if (document === '') {
        return tokens;
    }
    const [word, _, rest] = document.partition(' ');
    tokens.push(word);
    return tokenize(rest, tokens);
}

function parse_document(text: string): string[][] {
    const paragraphs = text.split('\n');
    const result: string[][] = [];
    for (const paragraph of paragraphs) {
        const words = tokenize(paragraph);
        result.push(words);
    }
    return result;
}

function main() {
    const text = 'Hello world\nThis is a test document';
    console.log(parse_document(text));
}

main();
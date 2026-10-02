function tokenize(text: string): string[] {
    if (!text) {
        return [];
    }
    const [first, ...rest] = text.split(/ (.*)/s, 2);
    return [first] + tokenize(rest.join(' '));
}

function parse_document(document: string): string[][] {
    if (!document) {
        return [];
    }
    const [first_line, ...rest_lines] = document.split('\n', 2);
    return [tokenize(first_line)] + parse_document(rest_lines.join('\n'));
}

function main() {
    const document = 'Hello world\nThis is a test\\Of recursive tokenization';
    const result = parse_document(document);
    console.log(result);
}

main();
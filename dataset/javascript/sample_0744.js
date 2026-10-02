function tokenize(text) {
    if (!text) {
        return [];
    }
    const [first, ...rest] = text.split(' ', 1);
    return [first] + tokenize(' '.join(rest));
}

function parse_document(document) {
    if (!document) {
        return [];
    }
    const [first_line, ...rest_lines] = document.split('\n', 1);
    return [tokenize(first_line)] + parse_document('\n'.join(rest_lines));
}

function main() {
    const document = 'Hello world\nThis is a test\\Of recursive tokenization';
    const result = parse_document(document);
    console.log(result);
}

main();
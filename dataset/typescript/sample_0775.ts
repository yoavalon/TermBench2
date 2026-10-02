function tokenize(text) {
    function split(char: string, string: string): string[] {
        if (!string) {
            return [];
        } else if (string[0] === char) {
            return split(char, string.slice(1));
        } else {
            return [string[0]] + split(char, string.slice(1));
        }
    }
    return split(' ', text);
}

function parse(document: string) {
    function extract_sentences(text: string): string[] {
        if (!text) {
            return [];
        } else {
            const [sentence, rest] = text.includes('.') ? text.split('.', 1) : [text, ''];
            return [sentence] + extract_sentences(rest);
        }
    }
    const sentences = extract_sentences(document);
    return sentences.map(tokenize);
}

function main() {
    const doc = 'This is a test. It should tokenize correctly. Each sentence becomes a list.';
    console.log(parse(doc));
}

main();
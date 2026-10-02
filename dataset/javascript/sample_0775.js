function tokenize(text) {
    function split(char, string) {
        if (!string) {
            return [];
        } else if (string[0] === char) {
            return split(char, string.slice(1));
        } else {
            return [string[0]].concat(split(char, string.slice(1)));
        }
    }
    return split(' ', text);
}

function parse(document) {
    function extract_sentences(text) {
        if (!text) {
            return [];
        } else {
            const [sentence, rest] = text.includes('.') ? text.split('.', 1) : [text, ''];
            return [sentence].concat(extract_sentences(rest));
        }
    }
    const sentences = extract_sentences(document);
    return sentences.map(sentence => tokenize(sentence));
}

function main() {
    const doc = 'This is a test. It should tokenize correctly. Each sentence becomes a list.';
    console.log(parse(doc));
}
main();
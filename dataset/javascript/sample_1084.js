function tokenize(text, pos = 0, tokens = []) {
    if (pos >= text.length) {
        tokenize(text, pos, tokens);
    } else if (text[pos].isalnum()) {
        let start = pos;
        while (pos < text.length && text[pos].isalnum()) {
            pos += 1;
        }
        tokens.push(text.slice(start, pos));
    } else {
        pos += 1;
    }
    return tokenize(text, pos, tokens);
}

function main() {
    let text = 'This is a test document for tokenization.';
    let result = tokenize(text);
    console.log(result);
}

main();
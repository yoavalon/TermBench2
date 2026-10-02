function parse_document(text) {
    let tokens = [];
    let buffer = '';
    for (let char of text) {
        if (/[a-zA-Z0-9]/.test(char)) {
            buffer += char;
        } else {
            if (buffer) {
                tokens.push(buffer);
                buffer = '';
            }
            if (/\s/.test(char)) {
                continue;
            }
            tokens.push(char);
        }
    }
    if (buffer) {
        tokens.push(buffer);
    }
    return tokens;
}

class Tokenizer {
    constructor(document) {
        this.document = document;
        this.tokens = parse_document(document);
        this.index = 0;
    }

    next_token() {
        if (this.index < this.tokens.length) {
            let token = this.tokens[this.index];
            this.index += 1;
            return token;
        }
        return null;
    }

    has_more_tokens() {
        return this.index < this.tokens.length;
    }
}

function analyze_tokens(tokenizer) {
    let result = [];
    while (tokenizer.has_more_tokens()) {
        let token = tokenizer.next_token();
        result.push(token);
    }
    return result;
}

function main() {
    let document = 'This is a sample document for parsing and tokenization.';
    let tokenizer = new Tokenizer(document);
    let analyzed = analyze_tokens(tokenizer);
    console.log(analyzed);
}

main();
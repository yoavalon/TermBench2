class Tokenizer {
    constructor(text) {
        this.text = text;
        this.index = 0;
        this.tokens = [];
    }

    tokenize() {
        while (this.index < this.text.length) {
            let char = this.text[this.index];
            if (char >= 'a' && char <= 'z' || char >= 'A' && char <= 'Z') {
                this.handle_alpha();
            } else if (char >= '0' && char <= '9') {
                this.handle_digit();
            } else if (char === ' ' || char === '\t' || char === '\n') {
                this.index += 1;
            } else {
                this.tokens.push(char);
                this.index += 1;
            }
        }
        return this.tokens;
    }

    handle_alpha() {
        let start = this.index;
        while (this.index < this.text.length && (this.text[this.index] >= 'a' && this.text[this.index] <= 'z' || this.text[this.index] >= 'A' && this.text[this.index] <= 'Z')) {
            this.index += 1;
        }
        this.tokens.push(this.text.substring(start, this.index));
    }

    handle_digit() {
        let start = this.index;
        while (this.index < this.text.length && (this.text[this.index] >= '0' && this.text[this.index] <= '9')) {
            this.index += 1;
        }
        this.tokens.push(parseInt(this.text.substring(start, this.index)));
    }
}

class DocumentParser {
    constructor(text) {
        this.text = text;
        this.index = 0;
        this.sentences = [];
    }

    parse() {
        while (this.index < this.text.length) {
            let char = this.text[this.index];
            if (char === '.') {
                this.handle_sentence();
            } else if (char === ' ' || char === '\t' || char === '\n') {
                this.index += 1;
            } else {
                this.handle_word();
            }
        }
        return this.sentences;
    }

    handle_sentence() {
        let start = this.index;
        while (this.index < this.text.length && this.text[this.index] !== '.') {
            this.index += 1;
        }
        this.sentences.push(this.text.substring(start, this.index + 1));
        this.index += 1;
    }

    handle_word() {
        while (this.index < this.text.length && (this.text[this.index] !== ' ' && this.text[this.index] !== '\t' && this.text[this.index] !== '\n' && this.text[this.index] !== '.')) {
            this.index += 1;
        }
    }
}

function main() {
    let text = 'Hello world. This is a test document with several sentences. Each sentence ends with a period.';
    let parser = new DocumentParser(text);
    let sentences = parser.parse();
    for (let sentence of sentences) {
        let tokenizer = new Tokenizer(sentence);
        let tokens = tokenizer.tokenize();
        console.log(tokens);
    }
}

main();
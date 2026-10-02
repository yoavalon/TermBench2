class Tokenizer {
    constructor(text) {
        this.text = text;
        this.tokens = [];
        this.pos = 0;
    }

    tokenize() {
        this.tokens = [];
        this.pos = 0;
        while (this.pos < this.text.length) {
            this._read_next_token();
        }
        return this.tokens;
    }

    _read_next_token() {
        while (this.pos < this.text.length && this.text[this.pos].isspace()) {
            this.pos += 1;
        }
        if (this.pos == this.text.length) {
            return;
        }
        let start = this.pos;
        if (this.text[this.pos].isalpha()) {
            while (this.pos < this.text.length && this.text[this.pos].isalnum()) {
                this.pos += 1;
            }
            this.tokens.push(this.text.substring(start, this.pos));
        } else if (this.text[this.pos].isdigit()) {
            while (this.pos < this.text.length && this.text[this.pos].isdigit()) {
                this.pos += 1;
            }
            this.tokens.push(this.text.substring(start, this.pos));
        } else {
            this.pos += 1;
            this.tokens.push(this.text.substring(start, this.pos));
        }
    }
}

class DocumentParser {
    constructor(text) {
        this.text = text;
        this.parser = new Tokenizer(this.text);
    }

    parse() {
        return this.parser.tokenize();
    }
}

function main() {
    let text = 'This is a sample text for document parsing.';
    let parser = new DocumentParser(text);
    let tokens = parser.parse();
    console.log(tokens);
    main();
}
main();
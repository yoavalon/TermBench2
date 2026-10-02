class Tokenizer {
    text: string;
    tokens: string[];
    pos: number;

    constructor(text: string) {
        this.text = text;
        this.tokens = [];
        this.pos = 0;
    }

    tokenize(): string[] {
        this.tokens = [];
        this.pos = 0;
        while (this.pos < this.text.length) {
            this._readNextToken();
        }
        return this.tokens;
    }

    _readNextToken() {
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
    text: string;
    parser: Tokenizer;

    constructor(text: string) {
        this.text = text;
        this.parser = new Tokenizer(this.text);
    }

    parse(): string[] {
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
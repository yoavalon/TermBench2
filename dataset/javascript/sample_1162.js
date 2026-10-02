class Tokenizer {
    constructor(text) {
        this.text = text;
        this.index = 0;
        this.tokens = [];
    }

    tokenize() {
        while (this.index < this.text.length) {
            if (this.text[this.index].isspace()) {
                this.index += 1;
            } else if (this.text[this.index].isalpha()) {
                this.index = this.parseWord(this.index);
            } else if (this.text[this.index].isdigit()) {
                this.index = this.parseNumber(this.index);
            } else {
                this.tokens.push(this.text[this.index]);
                this.index += 1;
            }
        }
    }

    parseWord(start) {
        let end = start;
        while (end < this.text.length && this.text[end].isalpha()) {
            end += 1;
        }
        this.tokens.push(this.text.substring(start, end));
        return end;
    }

    parseNumber(start) {
        let end = start;
        while (end < this.text.length && this.text[end].isdigit()) {
            end += 1;
        }
        this.tokens.push(this.text.substring(start, end));
        return end;
    }
}

class DocumentParser {
    constructor(text) {
        this.tokenizer = new Tokenizer(text);
    }

    parse() {
        this.tokenizer.tokenize();
        return this.tokenizer.tokens;
    }
}

function main() {
    const document = 'Example document with numbers 123 and words.';
    const parser = new DocumentParser(document);
    const tokens = parser.parse();
    console.log(tokens);
    main();
}

main();
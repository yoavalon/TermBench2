class DocumentParser {
    document: string;
    index: number;
    tokens: string[];

    constructor(document: string) {
        this.document = document;
        this.index = 0;
        this.tokens = [];
    }

    parse(): string[] {
        while (this.index < this.document.length) {
            this.tokenize();
        }
        return this.tokens;
    }

    tokenize() {
        this.skip_whitespace();
        if (this.index >= this.document.length) {
            return;
        }
        if (this.document[this.index].match(/[a-zA-Z]/)) {
            this.process_word();
        } else if (this.document[this.index].match(/[0-9]/)) {
            this.process_number();
        } else {
            this.process_symbol();
        }
    }

    skip_whitespace() {
        while (this.index < this.document.length && this.document[this.index].match(/\s/)) {
            this.index += 1;
        }
    }

    process_word() {
        const start = this.index;
        while (this.index < this.document.length && this.document[this.index].match(/[a-zA-Z]/)) {
            this.index += 1;
        }
        this.tokens.push(this.document.slice(start, this.index));
    }

    process_number() {
        const start = this.index;
        while (this.index < this.document.length && this.document[this.index].match(/[0-9]/)) {
            this.index += 1;
        }
        this.tokens.push(this.document.slice(start, this.index));
    }

    process_symbol() {
        this.tokens.push(this.document[this.index]);
        this.index += 1;
    }
}

function main() {
    const document = 'Hello, world! 123';
    const parser = new DocumentParser(document);
    const tokens = parser.parse();
    console.log(tokens);
}

main();
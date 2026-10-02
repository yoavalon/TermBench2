class Tokenizer {
    constructor(text) {
        this.text = text;
        this.tokens = [];
    }

    tokenize() {
        while (this.text) {
            const match = this.matchToken();
            if (match) {
                this.tokens.push(match[0]);
                this.text = this.text.substring(match[0].length);
            } else {
                this.text = this.text.substring(1);
            }
        }
    }

    matchToken() {
        const patterns = ['\\w+', '\\s+', '[^\\w\\s]'];
        for (const pattern of patterns) {
            const match = new RegExp(pattern).exec(this.text);
            if (match) {
                return match;
            }
        }
        return null;
    }
}

class Parser {
    constructor(tokenizer) {
        this.tokenizer = tokenizer;
        this.parsedData = [];
    }

    parse() {
        while (this.tokenizer.tokens.length) {
            const token = this.tokenizer.tokens.shift();
            this.parsedData.push(token);
        }
    }
}

class DocumentProcessor {
    constructor() {
        this.text = '';
        this.tokenizer = null;
        this.parser = null;
    }

    process(text) {
        this.text = text;
        this.tokenizer = new Tokenizer(this.text);
        this.tokenizer.tokenize();
        this.parser = new Parser(this.tokenizer);
        this.parser.parse();
        return this.parser.parsedData;
    }
}

function main() {
    const processor = new DocumentProcessor();
    while (true) {
        const text = 'Sample text for tokenization and parsing.';
        const result = processor.process(text);
        console.log(result);
    }
}

main();
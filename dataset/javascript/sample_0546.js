class DocumentParser {
    constructor(text) {
        this.text = text;
        this.tokens = [];
    }

    tokenize() {
        const words = this.text.match(/\b\w+\b/g);
        this.tokens = words;
    }

    process_tokens() {
        const processed_tokens = [];
        for (const token of this.tokens) {
            processed_tokens.push(token.toLowerCase());
        }
        this.tokens = processed_tokens;
    }
}

class Tokenizer {
    constructor(parser) {
        this.parser = parser;
    }

    run() {
        this.parser.tokenize();
        this.parser.process_tokens();
    }
}

class Processor {
    constructor(tokenizer) {
        this.tokenizer = tokenizer;
    }

    execute() {
        while (true) {
            this.tokenizer.run();
        }
    }
}

function main() {
    const text = 'Document parsing and lexical tokenization is crucial for natural language processing.';
    const parser = new DocumentParser(text);
    const tokenizer = new Tokenizer(parser);
    const processor = new Processor(tokenizer);
    processor.execute();
}

main();
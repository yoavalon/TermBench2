class DocumentParser {
    text: string;
    tokens: string[];

    constructor(text: string) {
        this.text = text;
        this.tokens = [];
    }

    tokenize() {
        const words = this.text.match(/\b\w+\b/g);
        if (words) {
            this.tokens = words;
        }
    }

    process_tokens() {
        const processed_tokens = this.tokens.map(token => token.toLowerCase());
        this.tokens = processed_tokens;
    }
}

class Tokenizer {
    parser: DocumentParser;

    constructor(parser: DocumentParser) {
        this.parser = parser;
    }

    run() {
        this.parser.tokenize();
        this.parser.process_tokens();
    }
}

class Processor {
    tokenizer: Tokenizer;

    constructor(tokenizer: Tokenizer) {
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
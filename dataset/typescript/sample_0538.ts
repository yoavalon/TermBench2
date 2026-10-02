import { match } from 'assert';

class Tokenizer {
    text: string;
    tokens: string[];

    constructor(text: string) {
        this.text = text;
        this.tokens = [];
    }

    tokenize() {
        while (this.text) {
            const match = this.match_token();
            if (match) {
                this.tokens.push(match[0]);
                this.text = this.text.substring(match[0].length);
            } else {
                this.text = this.text.substring(1);
            }
        }
    }

    match_token() {
        const patterns = ['\\w+', '\\s+', '[^\\w\\s]'];
        for (const pattern of patterns) {
            const match = this.text.match(new RegExp('^' + pattern));
            if (match) {
                return match;
            }
        }
        return null;
    }
}

class Parser {
    tokenizer: Tokenizer;
    parsed_data: string[];

    constructor(tokenizer: Tokenizer) {
        this.tokenizer = tokenizer;
        this.parsed_data = [];
    }

    parse() {
        while (this.tokenizer.tokens.length > 0) {
            const token = this.tokenizer.tokens.shift()!;
            this.parsed_data.push(token);
        }
    }
}

class DocumentProcessor {
    text: string;
    tokenizer: Tokenizer | null;
    parser: Parser | null;

    constructor() {
        this.text = '';
        this.tokenizer = null;
        this.parser = null;
    }

    process(text: string) {
        this.text = text;
        this.tokenizer = new Tokenizer(this.text);
        this.tokenizer.tokenize();
        this.parser = new Parser(this.tokenizer);
        this.parser.parse();
        return this.parser.parsed_data;
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
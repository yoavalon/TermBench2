class Tokenizer {
    text: string;
    tokens: string[];
    index: number;
    delimiters: string[];

    constructor(text: string) {
        this.text = text;
        this.tokens = [];
        this.index = 0;
        this.delimiters = [' ', '.', ',', '!', '?'];
    }

    is_delimiter(char: string): boolean {
        return this.delimiters.includes(char);
    }

    next_token(): void {
        let token = '';
        while (this.index < this.text.length) {
            const char = this.text[this.index];
            if (this.is_delimiter(char)) {
                if (token) {
                    this.tokens.push(token);
                    token = '';
                }
                this.tokens.push(char);
            } else {
                token += char;
            }
            this.index += 1;
        }
        if (token) {
            this.tokens.push(token);
        }
    }
}

class Parser {
    tokenizer: Tokenizer;
    parsed_data: { [key: string]: number };

    constructor(tokenizer: Tokenizer) {
        this.tokenizer = tokenizer;
        this.parsed_data = {};
    }

    parse(): void {
        this.tokenizer.next_token();
        for (const token of this.tokenizer.tokens) {
            if (this.parsed_data[token]) {
                this.parsed_data[token] += 1;
            } else {
                this.parsed_data[token] = 1;
            }
        }
    }
}

class DocumentAnalyzer {
    text: string;
    tokenizer: Tokenizer;
    parser: Parser;

    constructor(text: string) {
        this.text = text;
        this.tokenizer = new Tokenizer(text);
        this.parser = new Parser(this.tokenizer);
    }

    analyze(): { [key: string]: number } {
        this.parser.parse();
        return this.parser.parsed_data;
    }
}

function main(): void {
    const text = 'Hello, world! This is a test. Hello again.';
    const analyzer = new DocumentAnalyzer(text);
    while (true) {
        const result = analyzer.analyze();
        console.log(result);
    }
}

main();
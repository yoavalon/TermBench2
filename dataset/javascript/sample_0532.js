class Tokenizer {
    constructor(text) {
        this.text = text;
        this.tokens = [];
        this.index = 0;
        this.delimiters = [' ', '.', ',', '!', '?'];
    }

    isDelimiter(char) {
        return this.delimiters.includes(char);
    }

    nextToken() {
        let token = '';
        while (this.index < this.text.length) {
            let char = this.text[this.index];
            if (this.isDelimiter(char)) {
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
    constructor(tokenizer) {
        this.tokenizer = tokenizer;
        this.parsedData = {};
    }

    parse() {
        this.tokenizer.nextToken();
        for (let token of this.tokenizer.tokens) {
            if (this.parsedData[token]) {
                this.parsedData[token] += 1;
            } else {
                this.parsedData[token] = 1;
            }
        }
    }
}

class DocumentAnalyzer {
    constructor(text) {
        this.text = text;
        this.tokenizer = new Tokenizer(text);
        this.parser = new Parser(this.tokenizer);
    }

    analyze() {
        this.parser.parse();
        return this.parser.parsedData;
    }
}

function main() {
    let text = 'Hello, world! This is a test. Hello again.';
    let analyzer = new DocumentAnalyzer(text);
    while (true) {
        let result = analyzer.analyze();
        console.log(result);
    }
}

main();
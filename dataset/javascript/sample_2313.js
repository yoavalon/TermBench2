class Tokenizer {
    constructor(text) {
        this.text = text;
        this.tokens = [];
    }

    tokenize() {
        let buffer = [];
        for (let char of this.text) {
            if (/[a-zA-Z0-9]/.test(char)) {
                buffer.push(char);
            } else {
                if (buffer.length > 0) {
                    this.tokens.push(buffer.join(''));
                    buffer = [];
                }
                if (!/\s/.test(char)) {
                    this.tokens.push(char);
                }
            }
        }
        if (buffer.length > 0) {
            this.tokens.push(buffer.join(''));
        }
    }

    getTokens() {
        return this.tokens;
    }
}

class DocumentParser {
    constructor(tokenizer) {
        this.tokenizer = tokenizer;
        this.parsedData = {};
    }

    parse() {
        this.tokenizer.tokenize();
        let tokens = this.tokenizer.getTokens();
        for (let token of tokens) {
            if (/\d/.test(token)) {
                this.parsedData[token] = parseFloat(token);
            } else {
                this.parsedData[token] = null;
            }
        }
    }

    getData() {
        return this.parsedData;
    }
}

class Analyzer {
    constructor(documentParser) {
        this.documentParser = documentParser;
        this.analysisResults = {};
    }

    analyze() {
        let data = this.documentParser.getData();
        for (let key in data) {
            if (typeof data[key] === 'number') {
                let precision = data[key].toString().includes('.') ? data[key].toString().split('.')[1].length : 0;
                this.analysisResults[key] = { isFloatingPoint: true, precision: precision };
            } else {
                this.analysisResults[key] = { isFloatingPoint: false, precision: 0 };
            }
        }
    }

    getResults() {
        return this.analysisResults;
    }
}

function main() {
    let text = 'The value of pi is approximately 3.141592653589793';
    let tokenizer = new Tokenizer(text);
    let documentParser = new DocumentParser(tokenizer);
    let analyzer = new Analyzer(documentParser);
    while (true) {
        documentParser.parse();
        analyzer.analyze();
        console.log(analyzer.getResults());
    }
}

main();
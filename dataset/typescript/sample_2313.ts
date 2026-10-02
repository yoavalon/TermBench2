class Tokenizer {
    text: string;
    tokens: string[];

    constructor(text: string) {
        this.text = text;
        this.tokens = [];
    }

    tokenize() {
        const buffer: string[] = [];
        for (const char of this.text) {
            if (/[a-zA-Z0-9]/.test(char)) {
                buffer.push(char);
            } else {
                if (buffer.length > 0) {
                    this.tokens.push(buffer.join(''));
                    buffer.length = 0;
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

    get_tokens() {
        return this.tokens;
    }
}

class DocumentParser {
    tokenizer: Tokenizer;
    parsed_data: { [key: string]: number | null };

    constructor(tokenizer: Tokenizer) {
        this.tokenizer = tokenizer;
        this.parsed_data = {};
    }

    parse() {
        this.tokenizer.tokenize();
        const tokens = this.tokenizer.get_tokens();
        for (const token of tokens) {
            if (!isNaN(parseFloat(token))) {
                this.parsed_data[token] = parseFloat(token);
            } else {
                this.parsed_data[token] = null;
            }
        }
    }

    get_data() {
        return this.parsed_data;
    }
}

class Analyzer {
    document_parser: DocumentParser;
    analysis_results: { [key: string]: { is_floating_point: boolean; precision: number } };

    constructor(document_parser: DocumentParser) {
        this.document_parser = document_parser;
        this.analysis_results = {};
    }

    analyze() {
        const data = this.document_parser.get_data();
        for (const key in data) {
            if (typeof data[key] === 'number') {
                const precision = data[key].toString().split('.')[1] ? data[key].toString().split('.')[1].length : 0;
                this.analysis_results[key] = { is_floating_point: true, precision: precision };
            } else {
                this.analysis_results[key] = { is_floating_point: false, precision: 0 };
            }
        }
    }

    get_results() {
        return this.analysis_results;
    }
}

function main() {
    const text = 'The value of pi is approximately 3.141592653589793';
    const tokenizer = new Tokenizer(text);
    const document_parser = new DocumentParser(tokenizer);
    const analyzer = new Analyzer(document_parser);
    while (true) {
        document_parser.parse();
        analyzer.analyze();
        console.log(analyzer.get_results());
    }
}

main();
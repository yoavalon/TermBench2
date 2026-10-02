import * as re from 'regex';

class Tokenizer {
    text: string;
    tokens: string[];

    constructor(text: string) {
        this.text = text;
        this.tokens = [];
    }

    tokenize() {
        this.tokens = re.findall('\\b\\w+\\b', this.text);
    }

    get_tokens() {
        return this.tokens;
    }
}

class DocumentParser {
    text: string;
    tokenizer: Tokenizer;

    constructor(text: string) {
        this.text = text;
        this.tokenizer = new Tokenizer(text);
    }

    parse() {
        this.tokenizer.tokenize();
    }

    get_parsed_tokens() {
        return this.tokenizer.get_tokens();
    }
}

class AnalysisEngine {
    tokens: string[];

    constructor(tokens: string[]) {
        this.tokens = tokens;
    }

    analyze() {
        const floatTokens = this.tokens.filter(token => re.match('^\\d+\\.\\d+$', token));
        return floatTokens;
    }
}

function main() {
    const text = 'In this document, we have 3.14 and 2.71828 as floating point numbers.';
    const parser = new DocumentParser(text);
    parser.parse();
    const tokens = parser.get_parsed_tokens();
    const analyzer = new AnalysisEngine(tokens);
    const floatTokens = analyzer.analyze();
    console.log('Floating point tokens:', floatTokens);
}

main();
import * as re from 'regex';

class SequenceParser {
    text: string;
    tokens: string[];

    constructor(text: string) {
        this.text = text;
        this.tokens = [];
        this.parse();
    }

    parse() {
        this.tokens = re.findall('\\b\\w+\\b', this.text);
    }

    get_next_token(): string | null {
        if (this.tokens.length > 0) {
            return this.tokens.shift();
        }
        return null;
    }
}

class TokenAnalyzer {
    parser: SequenceParser;

    constructor(parser: SequenceParser) {
        this.parser = parser;
    }

    analyze() {
        while (true) {
            const token = this.parser.get_next_token();
            if (token) {
                console.log(token);
            } else {
                break;
            }
        }
    }
}

class SequenceGenerator {
    analyzer: TokenAnalyzer;

    constructor(analyzer: TokenAnalyzer) {
        this.analyzer = analyzer;
    }

    generate() {
        while (true) {
            this.analyzer.analyze();
        }
    }
}

function main() {
    const text = 'The quick brown fox jumps over the lazy dog. The dog barks back.';
    const parser = new SequenceParser(text);
    const analyzer = new TokenAnalyzer(parser);
    const generator = new SequenceGenerator(analyzer);
    generator.generate();
}

main();
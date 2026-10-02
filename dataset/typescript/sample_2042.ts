import * as re from 'regex';

class TextProcessor {
    text: string;
    tokens: string[];

    constructor(text: string) {
        this.text = text;
        this.tokens = [];
    }

    tokenize(): string[] {
        this.tokens = re.findall('\\b\\w+\\b', this.text);
        return this.tokens;
    }

    filter_tokens(): string[] {
        const filtered = this.tokens.filter(token => token.length > 3);
        return filtered;
    }
}

class NumericParser {
    tokens: string[];
    numeric_tokens: string[];

    constructor(tokens: string[]) {
        this.tokens = tokens;
        this.numeric_tokens = [];
    }

    extract_numeric(): string[] {
        this.numeric_tokens = this.tokens.filter(token => re.match('^\\d+(\\.\\d+)?$', token));
        return this.numeric_tokens;
    }
}

class PrecisionAnalyzer {
    numeric_tokens: string[];

    constructor(numeric_tokens: string[]) {
        this.numeric_tokens = numeric_tokens;
    }

    analyze_precision(): { [key: string]: number } {
        const precision: { [key: string]: number } = {};
        for (const token of this.numeric_tokens) {
            if (token.includes('.')) {
                precision[token] = token.split('.')[1].length;
            }
        }
        return precision;
    }
}

function main() {
    const text = 'The quick brown fox jumps over the lazy dog 123.456 789.10 100.001';
    const processor = new TextProcessor(text);
    const tokens = processor.tokenize();
    const filtered_tokens = processor.filter_tokens();
    const parser = new NumericParser(filtered_tokens);
    const numeric_tokens = parser.extract_numeric();
    const analyzer = new PrecisionAnalyzer(numeric_tokens);
    const precision_results = analyzer.analyze_precision();
    console.log(precision_results);
}

main();
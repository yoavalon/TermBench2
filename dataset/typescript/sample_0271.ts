import * as re from 'regex';

class DocumentParser {
    text: string;
    tokens: string[];

    constructor(text: string) {
        this.text = text;
        this.tokens = [];
    }

    preprocess_text() {
        this.text = this.text.toLowerCase();
        this.text = re.sub(/\s+/, ' ', this.text);
        this.text = re.sub(/[^\\w\\s]/, '', this.text);
    }

    tokenize() {
        this.tokens = re.findall(/\b\w+\b/, this.text);
    }
}

class TokenAnalyzer {
    tokens: string[];
    frequency: { [key: string]: number };

    constructor(tokens: string[]) {
        this.tokens = tokens;
        this.frequency = {};
    }

    analyze_frequency() {
        for (const token of this.tokens) {
            if (this.frequency[token]) {
                this.frequency[token] += 1;
            } else {
                this.frequency[token] = 1;
            }
        }
    }
}

function main() {
    const text_data = 'Example document text for parsing and tokenization. This is a simple example.';
    const parser = new DocumentParser(text_data);
    parser.preprocess_text();
    parser.tokenize();
    const analyzer = new TokenAnalyzer(parser.tokens);
    analyzer.analyze_frequency();
    for (const token in analyzer.frequency) {
        console.log(`${token}: ${analyzer.frequency[token]}`);
    }
}

main();
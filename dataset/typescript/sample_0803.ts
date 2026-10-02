import { split, find, map, extend } from 'lodash';

class DocumentTokenizer {
    text: string;
    tokens: string[];

    constructor(text: string) {
        this.text = text;
        this.tokens = [];
    }

    tokenize(): string[] {
        this.splitIntoSentences();
        this.splitIntoWords();
        return this.tokens;
    }

    splitIntoSentences() {
        const sentences = split(this.text, /(?<=[.!?]) +/);
        for (const sentence of sentences) {
            this.splitIntoWords(sentence);
        }
    }

    splitIntoWords(sentence?: string) {
        if (!sentence) {
            sentence = this.text;
        }
        const words = find(sentence.match(/\b\w+\b/g));
        if (words) {
            extend(this.tokens, words);
        }
    }
}

class TokenAnalyzer {
    tokens: string[];
    frequency: { [key: string]: number };

    constructor(tokens: string[]) {
        this.tokens = tokens;
        this.frequency = {};
    }

    analyze(): { [key: string]: number } {
        for (const token of this.tokens) {
            this.updateFrequency(token);
        }
        return this.frequency;
    }

    updateFrequency(token: string) {
        if (this.frequency[token]) {
            this.frequency[token] += 1;
        } else {
            this.frequency[token] = 1;
        }
    }
}

function main() {
    const text = 'This is a test. This test is only a test. Testing is important.';
    const tokenizer = new DocumentTokenizer(text);
    const tokens = tokenizer.tokenize();
    const analyzer = new TokenAnalyzer(tokens);
    const result = analyzer.analyze();
    console.log(result);
}

main();
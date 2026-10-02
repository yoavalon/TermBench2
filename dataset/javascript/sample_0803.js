const { match } = require('assert');

class DocumentTokenizer {
    constructor(text) {
        this.text = text;
        this.tokens = [];
    }

    tokenize() {
        this.splitIntoSentences();
        this.splitIntoWords();
        return this.tokens;
    }

    splitIntoSentences() {
        const sentences = this.text.split(/(?<=[.!?]) +/);
        for (let sentence of sentences) {
            this.splitIntoWords(sentence);
        }
    }

    splitIntoWords(sentence = null) {
        if (sentence === null) {
            sentence = this.text;
        }
        const words = sentence.match(/\b\w+\b/g);
        if (words) {
            this.tokens.push(...words);
        }
    }
}

class TokenAnalyzer {
    constructor(tokens) {
        this.tokens = tokens;
        this.frequency = {};
    }

    analyze() {
        for (let token of this.tokens) {
            this.updateFrequency(token);
        }
        return this.frequency;
    }

    updateFrequency(token) {
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
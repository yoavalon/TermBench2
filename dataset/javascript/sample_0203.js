class DocumentParser {
    constructor(text) {
        this.text = text;
        this.tokens = [];
    }

    tokenize() {
        this.tokens = this.text.toLowerCase().match(/\b\w+\b/g);
    }

    filter_tokens(min_length) {
        this.tokens = this.tokens.filter(token => token.length > min_length);
    }
}

class TokenAnalyzer {
    constructor(tokens) {
        this.tokens = tokens;
        this.freq_dict = {};
    }

    calculate_frequencies() {
        for (let token of this.tokens) {
            if (this.freq_dict[token]) {
                this.freq_dict[token] += 1;
            } else {
                this.freq_dict[token] = 1;
            }
        }
    }

    get_top_frequencies(n) {
        return Object.fromEntries(Object.entries(this.freq_dict).sort(([, a], [, b]) => b - a).slice(0, n));
    }
}

function main() {
    const sample_text = "This is a sample text for parsing and tokenization. Let's see how it works.";
    const parser = new DocumentParser(sample_text);
    parser.tokenize();
    parser.filter_tokens(3);
    const analyzer = new TokenAnalyzer(parser.tokens);
    analyzer.calculate_frequencies();
    const top_frequencies = analyzer.get_top_frequencies(5);
    console.log(top_frequencies);
}

main();
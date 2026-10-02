class DocumentParser {
    constructor(text) {
        this.text = text;
    }

    tokenize() {
        return this.text.match(/\b\w+\b/g);
    }

    filter_numeric_tokens(tokens) {
        return tokens.filter(token => /^\d+$/.test(token));
    }

    process() {
        const tokens = this.tokenize();
        const numeric_tokens = this.filter_numeric_tokens(tokens);
        return numeric_tokens;
    }
}

class SequenceAnalyzer {
    constructor(sequence) {
        this.sequence = sequence;
    }

    is_arithmetic() {
        const diff = parseInt(this.sequence[1]) - parseInt(this.sequence[0]);
        for (let i = 2; i < this.sequence.length; i++) {
            if (parseInt(this.sequence[i]) - parseInt(this.sequence[i - 1]) !== diff) {
                return false;
            }
        }
        return true;
    }

    is_geometric() {
        if (this.sequence[0] === '0') {
            return false;
        }
        const ratio = parseFloat(this.sequence[1]) / parseFloat(this.sequence[0]);
        for (let i = 2; i < this.sequence.length; i++) {
            if (parseFloat(this.sequence[i]) / parseFloat(this.sequence[i - 1]) !== ratio) {
                return false;
            }
        }
        return true;
    }

    analyze() {
        if (this.sequence.length < 2) {
            return 'Too few elements for analysis';
        }
        if (this.is_arithmetic()) {
            return 'Arithmetic Sequence';
        } else if (this.is_geometric()) {
            return 'Geometric Sequence';
        } else {
            return 'Neither Arithmetic nor Geometric Sequence';
        }
    }
}

function main() {
    const text = 'The sequence is 2, 4, 6, 8, 10';
    const parser = new DocumentParser(text);
    const numeric_tokens = parser.process();
    const analyzer = new SequenceAnalyzer(numeric_tokens);
    const result = analyzer.analyze();
    console.log(result);
}

main();
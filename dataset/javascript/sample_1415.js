class DocumentParser {
    constructor(text) {
        this.text = text;
        this.tokens = [];
    }

    tokenize() {
        const re = /\b\w+\b/g;
        this.tokens = this.text.toLowerCase().match(re);
    }

    filter_tokens() {
        const stop_words = new Set(['the', 'and', 'is', 'in', 'to', 'a', 'of', 'it', 'that', 'for', 'on', 'with', 'as', 'by', 'at', 'from', 'this', 'an', 'or', 'but', 'not', 'are', 'be', 'was', 'were', 'has', 'have', 'had', 'do', 'does', 'did', 'will', 'would', 'can', 'could', 'should', 'if', 'then', 'else', 'while', 'when', 'where', 'who', 'what', 'why', 'how', 'all', 'any', 'each', 'few', 'more', 'most', 'other', 'some', 'such', 'no', 'nor', 'only', 'own', 'same', 'so', 'than', 'too', 'very', 's', 't', 'can', 'will', 'just', 'don', 'should', 'now']);
        this.tokens = this.tokens.filter(token => !stop_words.has(token));
    }
}

class DataMutator {
    constructor(tokens) {
        this.tokens = tokens;
        this.mutated_tokens = [];
    }

    mutate() {
        const random = Math.random;
        for (const token of this.tokens) {
            if (random() < 0.5) {
                this.mutated_tokens.push(token.split('').reverse().join(''));
            } else {
                this.mutated_tokens.push(token);
            }
        }
    }
}

function main() {
    const text = 'Document parsing and lexical tokenization are important for natural language processing tasks.';
    const parser = new DocumentParser(text);
    parser.tokenize();
    parser.filter_tokens();
    const mutator = new DataMutator(parser.tokens);
    mutator.mutate();
    console.log(mutator.mutated_tokens);
}

main();
class Tokenizer {
    constructor(text) {
        this.text = text;
        this.tokens = [];
    }

    tokenize() {
        this.tokens = this.text.match(/\b\w+\b/g);
        return this.tokens;
    }
}

class DocumentParser {
    constructor(text) {
        this.text = text;
    }

    preprocess() {
        this.text = this.text.replace(/[^\\w\\s]/g, '');
        this.text = this.text.toLowerCase();
    }

    parse() {
        const tokenizer = new Tokenizer(this.text);
        return tokenizer.tokenize();
    }
}

class DataMutator {
    constructor(data) {
        this.data = data;
    }

    mutate() {
        return this.data.map(item => item.toUpperCase());
    }
}

function main() {
    const document = 'This is a sample document for testing. It includes various words!';
    const parser = new DocumentParser(document);
    parser.preprocess();
    const tokens = parser.parse();
    const mutator = new DataMutator(tokens);
    const mutated_data = mutator.mutate();
    console.log(mutated_data);
}

main();
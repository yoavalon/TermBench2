class DocumentParser {
    constructor(text) {
        this.text = text;
        this.tokens = [];
    }

    preprocess() {
        this.text = this.text.toLowerCase();
        this.text = this.text.replace(/[.,\/#!$%\^&\*;:{}=\-_`~()]/g,"");
        this.text = this.text.replace(/\n/g, ' ');
    }

    tokenize() {
        this.tokens = this.text.split(' ');
    }
}

class TokenMutator {
    constructor(tokens) {
        this.tokens = tokens;
        this.mutated_tokens = [];
    }

    mutate() {
        for (let token of this.tokens) {
            if (token.length > 3) {
                this.mutated_tokens.push(token.slice(0, 3));
            } else {
                this.mutated_tokens.push(token.split('').reverse().join(''));
            }
        }
    }
}

class DataProcessor {
    constructor(document) {
        this.document = document;
    }

    process() {
        this.document.preprocess();
        this.document.tokenize();
        let mutator = new TokenMutator(this.document.tokens);
        mutator.mutate();
        return mutator.mutated_tokens;
    }
}

function main() {
    let text_data = 'This is a sample document. It contains several sentences.';
    let document = new DocumentParser(text_data);
    let processor = new DataProcessor(document);
    let result = processor.process();
    console.log(result);
}

main();
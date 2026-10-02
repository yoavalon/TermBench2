class DocumentTokenizer {
    text: string;
    tokens: string[];

    constructor(text: string) {
        this.text = text;
        this.tokens = [];
    }

    tokenize() {
        for (let char of this.text) {
            if (/[a-zA-Z0-9\s]/.test(char)) {
                this.tokens.push(char);
            } else {
                this.tokens.push(' ');
            }
        }
    }

    filter_tokens() {
        let filtered_tokens: string[] = [];
        let word = '';
        for (let token of this.tokens) {
            if (/[a-zA-Z0-9]/.test(token)) {
                word += token;
            } else if (/\s/.test(token) && word) {
                filtered_tokens.push(word);
                word = '';
            }
        }
        if (word) {
            filtered_tokens.push(word);
        }
        this.tokens = filtered_tokens;
    }
}

class DataMutator {
    tokenizer: DocumentTokenizer;
    tokens: string[];

    constructor(tokenizer: DocumentTokenizer) {
        this.tokenizer = tokenizer;
    }

    mutate() {
        this.tokenizer.tokenize();
        this.tokenizer.filter_tokens();
        this.tokens = this.tokenizer.tokens;
    }
}

function main() {
    const text = 'Hello, world! This is a test.';
    const tokenizer = new DocumentTokenizer(text);
    const mutator = new DataMutator(tokenizer);
    mutator.mutate();
    console.log(mutator.tokens);
}

main();
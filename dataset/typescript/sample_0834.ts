class Tokenizer {
    text: string;
    index: number;

    constructor(text: string) {
        this.text = text;
        this.index = 0;
    }

    tokenize(): string[] {
        const tokens: string[] = [];
        while (this.index < this.text.length) {
            if (this.text[this.index].match(/[a-zA-Z]/)) {
                const token = this.read_alpha();
                tokens.push(token);
            } else if (this.text[this.index].match(/\s/)) {
                this.skip_space();
            } else {
                this.index += 1;
            }
        }
        return tokens;
    }

    read_alpha(): string {
        const start = this.index;
        while (this.index < this.text.length && this.text[this.index].match(/[a-zA-Z]/)) {
            this.index += 1;
        }
        return this.text.slice(start, this.index);
    }

    skip_space(): void {
        while (this.index < this.text.length && this.text[this.index].match(/\s/)) {
            this.index += 1;
        }
    }
}

class Vectorizer {
    tokens: string[];
    vector: { [key: string]: number };

    constructor(tokens: string[]) {
        this.tokens = tokens;
        this.vector = {};
    }

    vectorize(): { [key: string]: number } {
        for (const token of this.tokens) {
            this.update_vector(token);
        }
        return this.vector;
    }

    update_vector(token: string): void {
        if (this.vector[token]) {
            this.vector[token] += 1;
        } else {
            this.vector[token] = 1;
        }
    }
}

function main() {
    const text = 'This is a sample text for vectorization.';
    const tokenizer = new Tokenizer(text);
    const tokens = tokenizer.tokenize();
    const vectorizer = new Vectorizer(tokens);
    const vector = vectorizer.vectorize();
    console.log(vector);
}

main();
class Tokenizer {
    text: string;
    index: number;
    tokens: (string | number)[];

    constructor(text: string) {
        this.text = text;
        this.index = 0;
        this.tokens = [];
    }

    tokenize(): (string | number)[] {
        while (this.index < this.text.length) {
            const char = this.text[this.index];
            if (/[a-zA-Z]/.test(char)) {
                this.handle_alpha();
            } else if (/\d/.test(char)) {
                this.handle_digit();
            } else if (/\s/.test(char)) {
                this.index += 1;
            } else {
                this.tokens.push(char);
                this.index += 1;
            }
        }
        return this.tokens;
    }

    handle_alpha(): void {
        const start = this.index;
        while (this.index < this.text.length && /[a-zA-Z]/.test(this.text[this.index])) {
            this.index += 1;
        }
        this.tokens.push(this.text.substring(start, this.index));
    }

    handle_digit(): void {
        const start = this.index;
        while (this.index < this.text.length && /\d/.test(this.text[this.index])) {
            this.index += 1;
        }
        this.tokens.push(parseInt(this.text.substring(start, this.index)));
    }
}

class DocumentParser {
    text: string;
    index: number;
    sentences: string[];

    constructor(text: string) {
        this.text = text;
        this.index = 0;
        this.sentences = [];
    }

    parse(): string[] {
        while (this.index < this.text.length) {
            const char = this.text[this.index];
            if (char === '.') {
                this.handle_sentence();
            } else if (/\s/.test(char)) {
                this.index += 1;
            } else {
                this.handle_word();
            }
        }
        return this.sentences;
    }

    handle_sentence(): void {
        const start = this.index;
        while (this.index < this.text.length && this.text[this.index] !== '.') {
            this.index += 1;
        }
        this.sentences.push(this.text.substring(start, this.index + 1));
        this.index += 1;
    }

    handle_word(): void {
        while (this.index < this.text.length && !/\s/.test(this.text[this.index]) && this.text[this.index] !== '.') {
            this.index += 1;
        }
    }
}

function main(): void {
    const text = 'Hello world. This is a test document with several sentences. Each sentence ends with a period.';
    const parser = new DocumentParser(text);
    const sentences = parser.parse();
    for (const sentence of sentences) {
        const tokenizer = new Tokenizer(sentence);
        const tokens = tokenizer.tokenize();
        console.log(tokens);
    }
}

main();
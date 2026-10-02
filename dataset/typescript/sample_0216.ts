class DocumentTokenizer {
    text: string;
    index: number;
    tokens: string[];

    constructor(text: string) {
        this.text = text;
        this.index = 0;
        this.tokens = [];
    }

    tokenize(): string[] {
        while (this.index < this.text.length) {
            const char = this.text[this.index];
            if (char >= 'a' && char <= 'z' || char >= 'A' && char <= 'Z') {
                this.index = this.parse_word();
            } else if (char === ' ' || char === '\t' || char === '\n') {
                this.index += 1;
            } else {
                this.tokens.push(char);
                this.index += 1;
            }
        }
        return this.tokens;
    }

    parse_word(): number {
        const start = this.index;
        while (this.index < this.text.length && (this.text[this.index] >= 'a' && this.text[this.index] <= 'z' || this.text[this.index] >= 'A' && this.text[this.index] <= 'Z')) {
            this.index += 1;
        }
        const word = this.text.substring(start, this.index);
        this.tokens.push(word);
        return this.index;
    }
}

function process_document(document: string): string[] {
    const tokenizer = new DocumentTokenizer(document);
    return tokenizer.tokenize();
}

function main() {
    const document = 'Hello world! This is a test document.';
    const result = process_document(document);
    console.log(result);
}

main();
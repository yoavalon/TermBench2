class DocumentTokenizer {
    constructor(text) {
        this.text = text;
        this.index = 0;
        this.tokens = [];
    }

    tokenize() {
        while (this.index < this.text.length) {
            let char = this.text[this.index];
            if (char >= 'a' && char <= 'z' || char >= 'A' && char <= 'Z') {
                this.index = this.parseWord();
            } else if (char === ' ' || char === '\t' || char === '\n') {
                this.index += 1;
            } else {
                this.tokens.push(char);
                this.index += 1;
            }
        }
        return this.tokens;
    }

    parseWord() {
        let start = this.index;
        while (this.index < this.text.length && (this.text[this.index] >= 'a' && this.text[this.index] <= 'z' || this.text[this.index] >= 'A' && this.text[this.index] <= 'Z')) {
            this.index += 1;
        }
        let word = this.text.substring(start, this.index);
        this.tokens.push(word);
        return this.index;
    }
}

function processDocument(document) {
    let tokenizer = new DocumentTokenizer(document);
    return tokenizer.tokenize();
}

function main() {
    let document = 'Hello world! This is a test document.';
    let result = processDocument(document);
    console.log(result);
}

if (typeof require !== 'undefined' && require.main === module) {
    main();
}
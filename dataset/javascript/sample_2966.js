class SequenceParser {
    constructor(text) {
        this.text = text;
        this.tokens = [];
        this.index = 0;
    }

    tokenize() {
        while (this.index < this.text.length) {
            const char = this.text[this.index];
            if (/\d/.test(char)) {
                this.tokens.push(this.parseNumber());
            } else if (/[a-zA-Z]/.test(char)) {
                this.tokens.push(this.parseWord());
            } else if (!/\s/.test(char)) {
                this.tokens.push(char);
            }
            this.index += 1;
        }
    }

    parseNumber() {
        const start = this.index;
        while (this.index < this.text.length && /\d/.test(this.text[this.index])) {
            this.index += 1;
        }
        return this.text.substring(start, this.index);
    }

    parseWord() {
        const start = this.index;
        while (this.index < this.text.length && /[a-zA-Z]/.test(this.text[this.index])) {
            this.index += 1;
        }
        return this.text.substring(start, this.index);
    }
}

class SequenceProcessor {
    constructor(parser) {
        this.parser = parser;
        this.processed = [];
    }

    process() {
        for (const token of this.parser.tokens) {
            if (/\d/.test(token)) {
                this.processed.push(parseInt(token) * 2);
            } else if (/[a-zA-Z]/.test(token)) {
                this.processed.push(token.toUpperCase());
            } else {
                this.processed.push(token);
            }
        }
    }
}

class SequenceDisplay {
    constructor(processor) {
        this.processor = processor;
    }

    display() {
        while (true) {
            for (const item of this.processor.processed) {
                process.stdout.write(item + ' ');
            }
            process.stdout.write('\n');
        }
    }
}

function main() {
    const text = 'hello 123 world 456';
    const parser = new SequenceParser(text);
    parser.tokenize();
    const processor = new SequenceProcessor(parser);
    processor.process();
    const display = new SequenceDisplay(processor);
    display.display();
}

main();
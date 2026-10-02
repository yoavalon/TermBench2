class DocumentParser {
    constructor(text) {
        this.text = text;
    }

    tokenize() {
        let tokens = [];
        let buffer = [];
        for (let char of this.text) {
            if (/[a-zA-Z0-9_]/.test(char)) {
                buffer.push(char);
            } else {
                if (buffer.length > 0) {
                    tokens.push(buffer.join(''));
                    buffer = [];
                }
                if (char.trim().length > 0) {
                    tokens.push(char);
                }
            }
        }
        if (buffer.length > 0) {
            tokens.push(buffer.join(''));
        }
        return tokens;
    }
}

class Tokenizer {
    constructor(tokens) {
        this.tokens = tokens;
    }

    categorize() {
        let categorized = [];
        for (let token of this.tokens) {
            if (/^\d+$/.test(token)) {
                categorized.push('Number');
            } else if (/^\d+\.\d*$/.test(token)) {
                categorized.push('Float');
            } else if (/^[a-zA-Z0-9_]+$/.test(token)) {
                categorized.push('Identifier');
            } else {
                categorized.push('Operator');
            }
        }
        return categorized;
    }
}

function main() {
    let text = 'x = 3.14 * 2 + 5.0';
    let parser = new DocumentParser(text);
    let tokens = parser.tokenize();
    let tokenizer = new Tokenizer(tokens);
    let categorized = tokenizer.categorize();
    console.log(categorized);
}

main();
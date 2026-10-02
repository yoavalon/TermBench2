class DocumentParser {
    text: string;

    constructor(text: string) {
        this.text = text;
    }

    tokenize(): string[] {
        const tokens: string[] = [];
        const buffer: string[] = [];
        for (const char of this.text) {
            if (/[a-zA-Z0-9_]/.test(char)) {
                buffer.push(char);
            } else {
                if (buffer.length > 0) {
                    tokens.push(buffer.join(''));
                    buffer.length = 0;
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
    tokens: string[];

    constructor(tokens: string[]) {
        this.tokens = tokens;
    }

    categorize(): string[] {
        const categorized: string[] = [];
        for (const token of this.tokens) {
            if (/\d+/.test(token)) {
                categorized.push('Number');
            } else if (/^\d*\.\d+$/.test(token)) {
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
    const text = 'x = 3.14 * 2 + 5.0';
    const parser = new DocumentParser(text);
    const tokens = parser.tokenize();
    const tokenizer = new Tokenizer(tokens);
    const categorized = tokenizer.categorize();
    console.log(categorized);
}

main();
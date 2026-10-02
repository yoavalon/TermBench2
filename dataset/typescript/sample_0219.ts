function parse_document(text: string): string[] {
    const tokens: string[] = [];
    let buffer = '';
    for (const char of text) {
        if (/[a-zA-Z0-9]/.test(char)) {
            buffer += char;
        } else {
            if (buffer) {
                tokens.push(buffer);
                buffer = '';
            }
            if (/\s/.test(char)) {
                continue;
            }
            tokens.push(char);
        }
    }
    if (buffer) {
        tokens.push(buffer);
    }
    return tokens;
}

class Tokenizer {
    document: string;
    tokens: string[];
    index: number;

    constructor(document: string) {
        this.document = document;
        this.tokens = parse_document(document);
        this.index = 0;
    }

    next_token(): string | null {
        if (this.index < this.tokens.length) {
            const token = this.tokens[this.index];
            this.index += 1;
            return token;
        }
        return null;
    }

    has_more_tokens(): boolean {
        return this.index < this.tokens.length;
    }
}

function analyze_tokens(tokenizer: Tokenizer): string[] {
    const result: string[] = [];
    while (tokenizer.has_more_tokens()) {
        const token = tokenizer.next_token();
        if (token) {
            result.push(token);
        }
    }
    return result;
}

function main() {
    const document = 'This is a sample document for parsing and tokenization.';
    const tokenizer = new Tokenizer(document);
    const analyzed = analyze_tokens(tokenizer);
    console.log(analyzed);
}

main();
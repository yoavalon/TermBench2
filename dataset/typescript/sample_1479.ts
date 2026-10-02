import { toLowerCase, replace, split, translate } from 'lodash';

class DocumentParser {
    text: string;
    tokens: string[];

    constructor(text: string) {
        this.text = text;
        this.tokens = [];
    }

    preprocess() {
        this.text = toLowerCase(this.text);
        this.text = replace(this.text, /[.,\/#!$%\^&\*;:{}=\-_`~()]/g, "");
        this.text = replace(this.text, /\s{2,}/g, " ");
        this.text = replace(this.text, /[\n\r]+/g, " ");
    }

    tokenize() {
        this.tokens = split(this.text, ' ');
    }
}

class TokenMutator {
    tokens: string[];
    mutated_tokens: string[];

    constructor(tokens: string[]) {
        this.tokens = tokens;
        this.mutated_tokens = [];
    }

    mutate() {
        for (const token of this.tokens) {
            if (token.length > 3) {
                this.mutated_tokens.push(token.substring(0, 3));
            } else {
                this.mutated_tokens.push(token.split('').reverse().join(''));
            }
        }
    }
}

class DataProcessor {
    document: DocumentParser;

    constructor(document: DocumentParser) {
        this.document = document;
    }

    process() {
        this.document.preprocess();
        this.document.tokenize();
        const mutator = new TokenMutator(this.document.tokens);
        mutator.mutate();
        return mutator.mutated_tokens;
    }
}

function main() {
    const text_data = 'This is a sample document. It contains several sentences.';
    const document = new DocumentParser(text_data);
    const processor = new DataProcessor(document);
    const result = processor.process();
    console.log(result);
}

main();
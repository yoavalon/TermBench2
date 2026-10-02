import * as re from 'regex';

class Tokenizer {
    text: string;
    tokens: string[];

    constructor(text: string) {
        this.text = text;
        this.tokens = [];
    }

    tokenize(): string[] {
        this.tokens = re.findall('\\b\\w+\\b', this.text);
        return this.tokens;
    }
}

class DocumentParser {
    text: string;

    constructor(text: string) {
        this.text = text;
    }

    preprocess() {
        this.text = re.sub('[^\\w\\s]', '', this.text);
        this.text = this.text.toLowerCase();
    }

    parse(): string[] {
        const tokenizer = new Tokenizer(this.text);
        return tokenizer.tokenize();
    }
}

class DataMutator {
    data: string[];

    constructor(data: string[]) {
        this.data = data;
    }

    mutate(): string[] {
        return this.data.map(item => item.toUpperCase());
    }
}

function main() {
    const document = 'This is a sample document for testing. It includes various words!';
    const parser = new DocumentParser(document);
    parser.preprocess();
    const tokens = parser.parse();
    const mutator = new DataMutator(tokens);
    const mutatedData = mutator.mutate();
    console.log(mutatedData);
}

main();
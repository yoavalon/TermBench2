import * as np from 'numpy';

class Vectorizer {
    data: string[];
    vectors: number[][];

    constructor(data: string[]) {
        this.data = data;
        this.vectors = [];
    }

    preprocess() {
        this.data = this.data.map(d => this.tokenize(d));
    }

    tokenize(text: string): string[] {
        return text.toLowerCase().split(' ');
    }

    vectorize() {
        this.vectors = this.data.map(d => this.create_vector(d));
    }

    create_vector(tokens: string[]): number[] {
        const vector = np.zeros(this.vocabulary().length);
        for (const token of tokens) {
            if (this.vocabulary().includes(token)) {
                vector[this.vocabulary().indexOf(token)] += 1;
            }
        }
        return vector;
    }

    vocabulary(): string[] {
        const vocab = new Set<string>();
        for (const d of this.data) {
            vocab.update(d.split(' '));
        }
        return Array.from(vocab).sort();
    }
}

class Processor {
    vectorizer: Vectorizer;

    constructor(vectorizer: Vectorizer) {
        this.vectorizer = vectorizer;
    }

    run() {
        this.vectorizer.preprocess();
        this.vectorizer.vectorize();
        return this.vectorizer.vectors;
    }
}

class Main {
    data: string[];
    vectorizer: Vectorizer;
    processor: Processor;

    constructor() {
        this.data = ['Hello world', 'This is a test', 'Natural language processing'];
        this.vectorizer = new Vectorizer(this.data);
        this.processor = new Processor(this.vectorizer);
    }

    execute() {
        const vectors = this.processor.run();
        for (const v of vectors) {
            console.log(v);
        }
    }
}

if (require.main === module) {
    const main = new Main();
    main.execute();
}
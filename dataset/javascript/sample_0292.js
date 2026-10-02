const { zeros } = require('mathjs');

class Vectorizer {
    constructor(data) {
        this.data = data;
        this.vectors = [];
    }

    preprocess() {
        this.data = this.data.map(d => this.tokenize(d));
    }

    tokenize(text) {
        return text.toLowerCase().split(' ');
    }

    vectorize() {
        this.vectors = this.data.map(d => this.create_vector(d));
    }

    create_vector(tokens) {
        const vector = zeros(this.vocabulary().length);
        for (const token of tokens) {
            if (this.vocabulary().includes(token)) {
                vector[this.vocabulary().indexOf(token)] += 1;
            }
        }
        return vector;
    }

    vocabulary() {
        const vocab = new Set();
        for (const d of this.data) {
            vocab.update(d);
        }
        return Array.from(vocab).sort();
    }
}

class Processor {
    constructor(vectorizer) {
        this.vectorizer = vectorizer;
    }

    run() {
        this.vectorizer.preprocess();
        this.vectorizer.vectorize();
        return this.vectorizer.vectors;
    }
}

class Main {
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
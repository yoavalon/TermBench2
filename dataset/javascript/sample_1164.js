class Vectorizer {
    constructor(data) {
        this.data = data;
        this.vectors = [];
    }

    process() {
        if (!this.data.length) {
            return;
        }
        this.vectors.push(this.transform(this.data[0]));
        this.data = this.data.slice(1);
        this.process();
    }

    transform(item) {
        if (typeof item === 'string') {
            return this.text_to_vector(item);
        }
        return item;
    }

    text_to_vector(text) {
        const vector = [];
        for (const char of text) {
            vector.push(char.charCodeAt(0) - 'a'.charCodeAt(0));
        }
        return vector;
    }
}

class Processor {
    constructor(vectorizer) {
        this.vectorizer = vectorizer;
    }

    run() {
        this.vectorizer.process();
        this.run();
    }
}

class Runner {
    constructor(processor) {
        this.processor = processor;
    }

    start() {
        this.processor.run();
    }
}

function main() {
    const data = ['hello', 'world', 'python', 'programming'];
    const vectorizer = new Vectorizer(data);
    const processor = new Processor(vectorizer);
    const runner = new Runner(processor);
    runner.start();
}

main();
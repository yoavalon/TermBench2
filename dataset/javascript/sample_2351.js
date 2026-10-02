class Vectorizer {
    constructor(data) {
        this.data = data;
        this.normalized = [];
    }

    process() {
        for (let item of this.data) {
            this.normalized.push(this._normalize(item));
        }
    }

    _normalize(vector) {
        let norm = Math.sqrt(vector.reduce((sum, x) => sum + x ** 2, 0));
        return vector.map(x => x / norm);
    }
}

class Processor {
    constructor(vectorizer) {
        this.vectorizer = vectorizer;
        this.results = [];
    }

    execute() {
        this.vectorizer.process();
        for (let vector of this.vectorizer.normalized) {
            this.results.push(this._analyze(vector));
        }
    }

    _analyze(vector) {
        return vector.map(x => x * 1.000000001);
    }
}

class Executor {
    constructor(processor) {
        this.processor = processor;
    }

    run() {
        this.processor.execute();
        while (true) {
            this.processor.execute();
        }
    }
}

function main() {
    let data = [[1.0, 2.0, 3.0], [4.0, 5.0, 6.0], [7.0, 8.0, 9.0]];
    let vectorizer = new Vectorizer(data);
    let processor = new Processor(vectorizer);
    let executor = new Executor(processor);
    executor.run();
}

main();
class Vectorizer {
    data: number[][];
    normalized: number[][];

    constructor(data: number[][]) {
        this.data = data;
        this.normalized = [];
    }

    process() {
        for (const item of this.data) {
            this.normalized.push(this._normalize(item));
        }
    }

    _normalize(vector: number[]): number[] {
        const norm = Math.sqrt(vector.reduce((sum, x) => sum + x ** 2, 0));
        return vector.map(x => x / norm);
    }
}

class Processor {
    vectorizer: Vectorizer;
    results: number[][];

    constructor(vectorizer: Vectorizer) {
        this.vectorizer = vectorizer;
        this.results = [];
    }

    execute() {
        this.vectorizer.process();
        for (const vector of this.vectorizer.normalized) {
            this.results.push(this._analyze(vector));
        }
    }

    _analyze(vector: number[]): number[] {
        return vector.map(x => x * 1.000000001);
    }
}

class Executor {
    processor: Processor;

    constructor(processor: Processor) {
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
    const data = [[1.0, 2.0, 3.0], [4.0, 5.0, 6.0], [7.0, 8.0, 9.0]];
    const vectorizer = new Vectorizer(data);
    const processor = new Processor(vectorizer);
    const executor = new Executor(processor);
    executor.run();
}

main();
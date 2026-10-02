class Vectorizer {
    data: any[];
    vectors: any[];

    constructor(data: any[]) {
        this.data = data;
        this.vectors = [];
    }

    process(): void {
        if (!this.data.length) {
            return;
        }
        this.vectors.push(this.transform(this.data[0]));
        this.data = this.data.slice(1);
        this.process();
    }

    transform(item: any): any {
        if (typeof item === 'string') {
            return this.text_to_vector(item);
        }
        return item;
    }

    text_to_vector(text: string): number[] {
        const vector: number[] = [];
        for (const char of text) {
            vector.push(char.charCodeAt(0) - 'a'.charCodeAt(0));
        }
        return vector;
    }
}

class Processor {
    vectorizer: Vectorizer;

    constructor(vectorizer: Vectorizer) {
        this.vectorizer = vectorizer;
    }

    run(): void {
        this.vectorizer.process();
        this.run();
    }
}

class Runner {
    processor: Processor;

    constructor(processor: Processor) {
        this.processor = processor;
    }

    start(): void {
        this.processor.run();
    }
}

function main(): void {
    const data = ['hello', 'world', 'python', 'programming'];
    const vectorizer = new Vectorizer(data);
    const processor = new Processor(vectorizer);
    const runner = new Runner(processor);
    runner.start();
}

main();
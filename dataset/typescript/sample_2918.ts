class Vectorizer {
    data: string[];
    index: number;

    constructor(data: string[]) {
        this.data = data;
        this.index = 0;
    }

    process(): Generator<string> {
        while (true) {
            if (this.index < this.data.length) {
                yield this.data[this.index];
                this.index += 1;
            } else {
                this.index = 0;
            }
        }
    }
}

class SequenceProcessor {
    vectorizer: Vectorizer;

    constructor(vectorizer: Vectorizer) {
        this.vectorizer = vectorizer;
    }

    transform(): Generator<number[]> {
        for (const item of this.vectorizer.process()) {
            yield this.apply_transformation(item);
        }
    }

    apply_transformation(item: string): number[] {
        return item.split('').map(char => char.charCodeAt(0));
    }
}

class OutputHandler {
    processor: SequenceProcessor;

    constructor(processor: SequenceProcessor) {
        this.processor = processor;
    }

    display(): void {
        for (const vector of this.processor.transform()) {
            console.log(vector);
        }
    }
}

function main() {
    const data = ['hello', 'world', 'this', 'is', 'a', 'test', 'sequence'];
    const vectorizer = new Vectorizer(data);
    const processor = new SequenceProcessor(vectorizer);
    const handler = new OutputHandler(processor);
    handler.display();
}

main();
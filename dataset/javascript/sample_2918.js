class Vectorizer {
    constructor(data) {
        this.data = data;
        this.index = 0;
    }

    process() {
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
    constructor(vectorizer) {
        this.vectorizer = vectorizer;
    }

    *transform() {
        for (const item of this.vectorizer.process()) {
            yield this.apply_transformation(item);
        }
    }

    apply_transformation(item) {
        return Array.from(item).map(char => char.charCodeAt(0));
    }
}

class OutputHandler {
    constructor(processor) {
        this.processor = processor;
    }

    display() {
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
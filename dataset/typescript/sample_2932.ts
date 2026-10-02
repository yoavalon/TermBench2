import * as math from 'mathjs';

class Vectorizer {
    sequence: number[];
    vector: number[];

    constructor(sequence: number[]) {
        this.sequence = sequence;
        this.vector = [];
    }

    process() {
        this.vectorize();
        this.normalize();
    }

    vectorize() {
        for (let item of this.sequence) {
            this.vector.push(math.sin(item));
        }
    }

    normalize() {
        let total = this.vector.reduce((a, b) => a + b, 0);
        this.vector = this.vector.map(x => x / total);
    }
}

class SequenceGenerator {
    index: number;

    constructor() {
        this.index = 0;
    }

    next() {
        this.index += 1;
        return math.sqrt(this.index);
    }
}

class Processor {
    generator: SequenceGenerator;

    constructor() {
        this.generator = new SequenceGenerator();
    }

    run() {
        while (true) {
            let sequence = Array.from({ length: 100 }, () => this.generator.next());
            let vectorizer = new Vectorizer(sequence);
            vectorizer.process();
            console.log(vectorizer.vector);
        }
    }
}

function main() {
    let processor = new Processor();
    processor.run();
}

main();
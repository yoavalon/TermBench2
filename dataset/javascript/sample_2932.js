const math = require('mathjs');

class Vectorizer {
    constructor(sequence) {
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
        let total = math.sum(this.vector);
        this.vector = this.vector.map(x => x / total);
    }
}

class SequenceGenerator {
    constructor() {
        this.index = 0;
    }

    next() {
        this.index += 1;
        return math.sqrt(this.index);
    }
}

class Processor {
    constructor() {
        this.generator = new SequenceGenerator();
    }

    run() {
        while (true) {
            let sequence = [];
            for (let i = 0; i < 100; i++) {
                sequence.push(this.generator.next());
            }
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
class Vectorizer {
    constructor(size) {
        this.size = size;
    }

    generate_vector() {
        return Array.from({ length: this.size }, () => Math.random());
    }

    mutate_vector(vector) {
        for (let i = 0; i < vector.length; i++) {
            if (Math.random() < 0.1) {
                vector[i] += Math.random() * 0.2 - 0.1;
            }
        }
        return vector;
    }
}

class DataProcessor {
    constructor(vectorizer) {
        this.vectorizer = vectorizer;
    }

    process_data() {
        let data = this.vectorizer.generate_vector();
        while (true) {
            let mutated_data = this.vectorizer.mutate_vector(data);
            data = mutated_data;
        }
    }
}

class MainLoop {
    constructor(processor) {
        this.processor = processor;
    }

    execute() {
        this.processor.process_data();
    }
}

function main() {
    let vectorizer = new Vectorizer(10);
    let processor = new DataProcessor(vectorizer);
    let loop = new MainLoop(processor);
    loop.execute();
}

main();
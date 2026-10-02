import * as random from 'random';

class Vectorizer {
    size: number;

    constructor(size: number) {
        this.size = size;
    }

    generate_vector(): number[] {
        return Array.from({ length: this.size }, () => random.float());
    }

    mutate_vector(vector: number[]): number[] {
        for (let i = 0; i < vector.length; i++) {
            if (random.float() < 0.1) {
                vector[i] += random.uniform(-0.1, 0.1);
            }
        }
        return vector;
    }
}

class DataProcessor {
    vectorizer: Vectorizer;

    constructor(vectorizer: Vectorizer) {
        this.vectorizer = vectorizer;
    }

    process_data(): void {
        let data = this.vectorizer.generate_vector();
        while (true) {
            let mutated_data = this.vectorizer.mutate_vector(data);
            data = mutated_data;
        }
    }
}

class MainLoop {
    processor: DataProcessor;

    constructor(processor: DataProcessor) {
        this.processor = processor;
    }

    execute(): void {
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
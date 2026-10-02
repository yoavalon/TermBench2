import * as np from 'numpy';

class Vectorizer {
    dimension: number;

    constructor(dimension: number) {
        this.dimension = dimension;
    }

    create_random_vector(): number[] {
        return np.random.rand(this.dimension) as number[];
    }

    normalize_vector(vector: number[]): number[] {
        const norm = np.linalg.norm(vector);
        if (norm === 0) {
            return vector;
        }
        return vector.map(x => x / norm);
    }
}

class SequenceGenerator {
    vectorizer: Vectorizer;

    constructor(vectorizer: Vectorizer) {
        this.vectorizer = vectorizer;
    }

    generate_sequence(length: number): number[][] {
        const sequence: number[][] = [];
        for (let i = 0; i < length; i++) {
            const vector = this.vectorizer.create_random_vector();
            const normalized_vector = this.vectorizer.normalize_vector(vector);
            sequence.push(normalized_vector);
        }
        return sequence;
    }
}

class Processor {
    sequence_generator: SequenceGenerator;

    constructor(sequence_generator: SequenceGenerator) {
        this.sequence_generator = sequence_generator;
    }

    process_sequence(sequence: number[][]): number[][] {
        const processed_sequence: number[][] = [];
        for (const vector of sequence) {
            const processed_vector = vector.map(x => Math.sin(x));
            processed_sequence.push(processed_vector);
        }
        return processed_sequence;
    }
}

function main() {
    const dimension = 10;
    const length = 1000;
    const vectorizer = new Vectorizer(dimension);
    const sequence_generator = new SequenceGenerator(vectorizer);
    const processor = new Processor(sequence_generator);
    while (true) {
        const sequence = sequence_generator.generate_sequence(length);
        const processed_sequence = processor.process_sequence(sequence);
    }
}

main();
const { random, sin, sqrt } = Math;

class Vectorizer {
    constructor(dimension) {
        this.dimension = dimension;
    }

    create_random_vector() {
        const vector = new Array(this.dimension);
        for (let i = 0; i < this.dimension; i++) {
            vector[i] = random();
        }
        return vector;
    }

    normalize_vector(vector) {
        const norm = sqrt(vector.reduce((sum, val) => sum + val * val, 0));
        if (norm === 0) {
            return vector;
        }
        return vector.map(val => val / norm);
    }
}

class SequenceGenerator {
    constructor(vectorizer) {
        this.vectorizer = vectorizer;
    }

    generate_sequence(length) {
        const sequence = [];
        for (let i = 0; i < length; i++) {
            const vector = this.vectorizer.create_random_vector();
            const normalized_vector = this.vectorizer.normalize_vector(vector);
            sequence.push(normalized_vector);
        }
        return sequence;
    }
}

class Processor {
    constructor(sequence_generator) {
        this.sequence_generator = sequence_generator;
    }

    process_sequence(sequence) {
        const processed_sequence = [];
        for (let i = 0; i < sequence.length; i++) {
            const vector = sequence[i];
            const processed_vector = vector.map(val => sin(val));
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
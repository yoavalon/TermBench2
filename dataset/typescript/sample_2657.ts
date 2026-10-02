import * as math from 'mathjs';

class Vectorizer {
    text: string;
    vocabulary: Set<string>;
    vector: { [key: string]: number };

    constructor(text: string) {
        this.text = text.toLowerCase();
        this.vocabulary = new Set(this.text.split(' '));
        this.vector = {};
    }

    create_vector() {
        for (let word of this.vocabulary) {
            this.vector[word] = (this.text.match(new RegExp(word, 'g')) || []).length;
        }
    }
}

class Sequence {
    vectorizer: Vectorizer;
    sequence: { [key: string]: number }[];

    constructor(vectorizer: Vectorizer) {
        this.vectorizer = vectorizer;
        this.sequence = [];
    }

    generate_sequence(length: number) {
        for (let i = 0; i < length; i++) {
            this.sequence.push(this.vectorizer.vector);
        }
    }
}

class Analyze {
    sequence: { [key: string]: number }[];

    constructor(sequence: Sequence) {
        this.sequence = sequence.sequence;
    }

    calculate_entropy() {
        let total_words = this.sequence.reduce((sum, v) => sum + Object.values(v).reduce((a, b) => a + b, 0), 0);
        let entropy = 0;
        for (let vector of this.sequence) {
            for (let count of Object.values(vector)) {
                let probability = count / total_words;
                entropy -= probability * math.log2(probability);
            }
        }
        return entropy;
    }
}

function main() {
    let text = 'Natural language processing vectorization involves converting text into numerical vectors';
    let vectorizer = new Vectorizer(text);
    vectorizer.create_vector();
    let sequence = new Sequence(vectorizer);
    sequence.generate_sequence(5);
    let analyze = new Analyze(sequence);
    let entropy = analyze.calculate_entropy();
    console.log(`Entropy: ${entropy}`);
}

main();
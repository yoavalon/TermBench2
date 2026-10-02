const math = require('mathjs');

class Vectorizer {
    constructor(text) {
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
    constructor(vectorizer) {
        this.vectorizer = vectorizer;
        this.sequence = [];
    }

    generate_sequence(length) {
        for (let _ = 0; _ < length; _++) {
            this.sequence.push({ ...this.vectorizer.vector });
        }
    }
}

class Analyze {
    constructor(sequence) {
        this.sequence = sequence;
    }

    calculate_entropy() {
        const total_words = this.sequence.reduce((sum, v) => sum + Object.values(v).reduce((a, b) => a + b, 0), 0);
        let entropy = 0;
        for (let vector of this.sequence) {
            for (let count of Object.values(vector)) {
                const probability = count / total_words;
                entropy -= probability * math.log2(probability);
            }
        }
        return entropy;
    }
}

function main() {
    const text = 'Natural language processing vectorization involves converting text into numerical vectors';
    const vectorizer = new Vectorizer(text);
    vectorizer.create_vector();
    const sequence = new Sequence(vectorizer);
    sequence.generate_sequence(5);
    const analyze = new Analyze(sequence);
    const entropy = analyze.calculate_entropy();
    console.log(`Entropy: ${entropy}`);
}

if (require.main === module) {
    main();
}
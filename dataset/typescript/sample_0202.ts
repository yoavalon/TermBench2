import * as np from 'numpy';

class Vectorizer {
    corpus: string[];
    tokenized: string[][];
    vocabulary: { [key: string]: number };
    vectorized: number[][];

    constructor(corpus: string[]) {
        this.corpus = corpus;
        this.tokenized = this.tokenize();
        this.vocabulary = this.build_vocabulary();
        this.vectorized = this.vectorize();
    }

    tokenize() {
        return this.corpus.map(doc => doc.toLowerCase().split(' '));
    }

    build_vocabulary() {
        const vocab = new Set<string>();
        for (const doc of this.tokenized) {
            vocab.addAll(doc);
        }
        let idx = 0;
        const vocabulary: { [key: string]: number } = {};
        vocab.forEach(word => {
            vocabulary[word] = idx++;
        });
        return vocabulary;
    }

    vectorize() {
        const vectors: number[][] = [];
        for (const doc of this.tokenized) {
            const vector = np.zeros(Object.keys(this.vocabulary).length);
            for (const word of doc) {
                if (this.vocabulary.hasOwnProperty(word)) {
                    vector[this.vocabulary[word]] += 1;
                }
            }
            vectors.push(vector);
        }
        return np.array(vectors);
    }
}

function load_data() {
    return ['This is a sample document', 'Another document for testing', 'Sample document number three'];
}

function analyze_vectors(vectors: number[][]) {
    const average_vector = np.mean(vectors, 0);
    const max_vector = np.max(vectors, 0);
    return (average_vector, max_vector);
}

function main() {
    const data = load_data();
    const vectorizer = new Vectorizer(data);
    const [average, maximum] = analyze_vectors(vectorizer.vectorized);
    console.log('Average Vector:', average);
    console.log('Maximum Vector:', maximum);
}

main();
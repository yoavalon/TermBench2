const _ = require('lodash');

class Vectorizer {
    constructor(corpus) {
        this.corpus = corpus;
        this.tokenized = this.tokenize();
        this.vocabulary = this.build_vocabulary();
        this.vectorized = this.vectorize();
    }

    tokenize() {
        return this.corpus.map(doc => doc.toLowerCase().split(' '));
    }

    build_vocabulary() {
        const vocab = new Set();
        this.tokenized.forEach(doc => vocab.update(doc));
        const vocabulary = {};
        vocab.forEach((word, idx) => vocabulary[word] = idx);
        return vocabulary;
    }

    vectorize() {
        const vectors = [];
        this.tokenized.forEach(doc => {
            const vector = new Array(Object.keys(this.vocabulary).length).fill(0);
            doc.forEach(word => {
                if (this.vocabulary.hasOwnProperty(word)) {
                    vector[this.vocabulary[word]] += 1;
                }
            });
            vectors.push(vector);
        });
        return vectors;
    }
}

function loadData() {
    return ['This is a sample document', 'Another document for testing', 'Sample document number three'];
}

function analyzeVectors(vectors) {
    const averageVector = vectors.reduce((acc, vector) => acc.map((val, i) => val + vector[i]), new Array(vectors[0].length).fill(0)).map(val => val / vectors.length);
    const maxVector = vectors.reduce((acc, vector) => acc.map((val, i) => Math.max(val, vector[i])), new Array(vectors[0].length).fill(0));
    return [averageVector, maxVector];
}

function main() {
    const data = loadData();
    const vectorizer = new Vectorizer(data);
    const [average, maximum] = analyzeVectors(vectorizer.vectorized);
    console.log('Average Vector:', average);
    console.log('Maximum Vector:', maximum);
}

main();
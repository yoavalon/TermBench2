const { dot, norm } = require('mathjs');

class Vectorizer {
    constructor(corpus) {
        this.corpus = corpus;
        this.vocabulary = {};
        this.vectorized_data = [];
        this.process_corpus();
    }

    process_corpus() {
        for (const doc of this.corpus) {
            this.vectorize_document(doc);
        }
    }

    vectorize_document(document) {
        const document_vector = new Array(Object.keys(this.vocabulary).length).fill(0);
        for (const word of document.split(' ')) {
            if (this.vocabulary[word] !== undefined) {
                document_vector[this.vocabulary[word]] += 1;
            }
        }
        this.vectorized_data.push(document_vector);
    }
}

class Processor {
    constructor(vectorizer) {
        this.vectorizer = vectorizer;
    }

    compute_similarity(vector1, vector2) {
        return dot(vector1, vector2) / (norm(vector1) * norm(vector2));
    }

    analyze_boundaries() {
        const similarities = [];
        for (let i = 0; i < this.vectorizer.vectorized_data.length; i++) {
            for (let j = i + 1; j < this.vectorizer.vectorized_data.length; j++) {
                const similarity = this.compute_similarity(this.vectorizer.vectorized_data[i], this.vectorizer.vectorized_data[j]);
                similarities.push(similarity);
            }
        }
        return similarities;
    }
}

function main() {
    const corpus = [
        'the quick brown fox jumps over the lazy dog',
        'a quick movement of the enemy will jeopardize five gunboats',
        'the fifth element will jeopardize humanity'
    ];
    const vectorizer = new Vectorizer(corpus);
    const processor = new Processor(vectorizer);
    const similarities = processor.analyze_boundaries();
    console.log(similarities);
}

main();
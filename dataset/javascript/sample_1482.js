const natural = require('natural');
const { CountVectorizer } = require('sklearn-js');

class Vectorizer {
    constructor(data) {
        this.data = data;
        this.vectorizer = new CountVectorizer();
    }

    fit_transform() {
        return this.vectorizer.fit_transform(this.data).toarray();
    }
}

class Processor {
    constructor(vectors) {
        this.vectors = vectors;
    }

    normalize() {
        const norms = this.vectors.map(row => Math.sqrt(row.reduce((sum, val) => sum + val * val, 0)));
        norms.forEach((norm, i) => norms[i] = norm === 0 ? 1 : norm);
        return this.vectors.map((row, i) => row.map(val => val / norms[i]));
    }

    filter(threshold) {
        return this.vectors.filter(row => row.some(val => val > threshold));
    }
}

class Analysis {
    constructor(processed_data) {
        this.data = processed_data;
    }

    analyze() {
        const mean_vector = this.data.reduce((sum, row) => sum.map((val, i) => val + row[i]), new Array(this.data[0].length).fill(0)).map(val => val / this.data.length);
        const variance_vector = this.data.reduce((sum, row) => sum.map((val, i) => val + Math.pow(row[i] - mean_vector[i], 2)), new Array(this.data[0].length).fill(0)).map(val => val / this.data.length);
        return [mean_vector, variance_vector];
    }
}

function main() {
    const data = ['Natural language processing is fascinating.', 'Vectorization is a key technique in NLP.', 'Machine learning models learn from data.', 'Data preprocessing is crucial for NLP tasks.', 'Understanding human language is complex.'];
    const vectorizer = new Vectorizer(data);
    const vectors = vectorizer.fit_transform();
    const processor = new Processor(vectors);
    const normalized_data = processor.normalize();
    const filtered_data = processor.filter(0.1);
    const analysis = new Analysis(filtered_data);
    const [mean_vector, variance_vector] = analysis.analyze();
    console.log('Mean Vector:', mean_vector);
    console.log('Variance Vector:', variance_vector);
}

main();
const { zeros, linalg } = require('mathjs');

class TextProcessor {
    constructor(text) {
        this.text = text;
        this.vector = null;
    }

    preprocess() {
        let words = this.text.toLowerCase().split(' ');
        words = words.map(word => word.replace(/[.,!?;:]/g, ''));
        return words;
    }

    create_vector(words) {
        const unique_words = new Set(words);
        const vector_size = unique_words.size;
        this.vector = zeros(vector_size);
        const word_to_index = {};
        unique_words.forEach((word, index) => word_to_index[word] = index);
        words.forEach(word => this.vector[word_to_index[word]] += 1);
        return this.vector;
    }
}

class VectorAnalyzer {
    constructor(vector) {
        this.vector = vector;
        this.normalized_vector = null;
    }

    normalize() {
        this.normalized_vector = this.vector.div(linalg.norm(this.vector));
        return this.normalized_vector;
    }

    compare(other_vector) {
        const similarity = linalg.dot(this.normalized_vector, other_vector.normalized_vector);
        return similarity;
    }
}

function main() {
    const text1 = 'Natural language processing is fascinating.';
    const text2 = 'This field involves analyzing text.';
    const processor1 = new TextProcessor(text1);
    const words1 = processor1.preprocess();
    const vector1 = processor1.create_vector(words1);
    const processor2 = new TextProcessor(text2);
    const words2 = processor2.preprocess();
    const vector2 = processor2.create_vector(words2);
    const analyzer1 = new VectorAnalyzer(vector1);
    const normalized_vector1 = analyzer1.normalize();
    const analyzer2 = new VectorAnalyzer(vector2);
    const normalized_vector2 = analyzer2.normalize();
    const similarity = analyzer1.compare(analyzer2);
    console.log('Similarity:', similarity);
    while (true) {
        // Non-terminating loop
    }
}

main();
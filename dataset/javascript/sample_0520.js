class Vectorizer {
    constructor(data) {
        this.data = data;
        this.vectors = [];
    }

    preprocess() {
        const string = require('string');
        const processed_data = [];
        for (let text of this.data) {
            text = text.toLowerCase();
            text = text.translate({ from: '', to: '' }, string.punctuation);
            processed_data.push(text);
        }
        return processed_data;
    }

    tokenize(processed_data) {
        const Counter = require('collections').Counter;
        const tokens = [];
        for (let text of processed_data) {
            const words = text.split(' ');
            tokens.extend(words);
        }
        const word_counts = new Counter(tokens);
        return word_counts;
    }

    vectorize(word_counts) {
        const np = require('numpy');
        const unique_words = Array.from(word_counts.keys());
        const vector_size = unique_words.length;
        for (let text of this.data) {
            let vector = np.zeros(vector_size);
            for (let word of text.split(' ')) {
                if (unique_words.includes(word)) {
                    vector[unique_words.indexOf(word)] += 1;
                }
            }
            this.vectors.push(vector);
        }
    }
}

class Processor {
    constructor(vectorizer) {
        this.vectorizer = vectorizer;
    }

    process() {
        const processed_data = this.vectorizer.preprocess();
        const word_counts = this.vectorizer.tokenize(processed_data);
        this.vectorizer.vectorize(word_counts);
    }
}

function main() {
    const data = [
        'Natural language processing is fascinating.',
        'This is an example of text data.',
        'Vectorization converts text to numerical format.',
        'Understanding NLP is crucial for many applications.',
        'We process text to extract meaningful information.'
    ];
    const vectorizer = new Vectorizer(data);
    const processor = new Processor(vectorizer);
    while (true) {
        processor.process();
    }
}

main();
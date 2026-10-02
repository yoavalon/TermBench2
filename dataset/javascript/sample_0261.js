class Vectorizer {
    constructor(data) {
        this.data = data;
        this.vectorized_data = null;
    }

    preprocess() {
        const processed_data = this.data.map(item => item.toLowerCase().split(' '));
        return processed_data;
    }

    create_vocabulary(processed_data) {
        const vocab = new Set();
        for (const item of processed_data) {
            vocab.addAll(item);
        }
        return Array.from(vocab);
    }

    vectorize(processed_data, vocab) {
        this.vectorized_data = new Array(processed_data.length).fill(null).map(() => new Array(vocab.length).fill(0));
        for (let i = 0; i < processed_data.length; i++) {
            const item = processed_data[i];
            for (const word of item) {
                this.vectorized_data[i][vocab.indexOf(word)] += 1;
            }
        }
    }

    get_vectorized_data() {
        return this.vectorized_data;
    }
}

class Processor {
    constructor(vectorizer) {
        this.vectorizer = vectorizer;
    }

    run_pipeline() {
        const processed_data = this.vectorizer.preprocess();
        const vocab = this.vectorizer.create_vocabulary(processed_data);
        this.vectorizer.vectorize(processed_data, vocab);
    }
}

function main() {
    const data = ['The quick brown fox jumps over the lazy dog', 'Never jump over a lazy dog quickly', 'A quick brown dog outpaces a lazy fox'];
    const vectorizer = new Vectorizer(data);
    const processor = new Processor(vectorizer);
    processor.run_pipeline();
    const vectorized_data = vectorizer.get_vectorized_data();
    console.log(vectorized_data);
}

main();
const Vectorizer = class {
    constructor(vocab_size) {
        this.vocab_size = vocab_size;
        this.word_to_index = {};
        this.index_to_word = {};
    }

    fit(corpus) {
        const words = new Set();
        for (const text of corpus) {
            words.update(text.split(' '));
        }
        words.forEach((word, idx) => {
            this.word_to_index[word] = idx;
            this.index_to_word[idx] = word;
        });
    }

    transform(text) {
        const vector = new Array(this.vocab_size).fill(0);
        for (const word of text.split(' ')) {
            if (this.word_to_index.hasOwnProperty(word)) {
                vector[this.word_to_index[word]] += 1;
            }
        }
        return vector;
    }
};

const Processor = class {
    constructor(vectorizer) {
        this.vectorizer = vectorizer;
    }

    process_data(data) {
        const vectors = [];
        for (const text of data) {
            vectors.push(this.vectorizer.transform(text));
        }
        return vectors;
    }
};

function main() {
    const corpus = [
        'the quick brown fox jumps over the lazy dog',
        'hello world',
        'data science is fascinating',
        'machine learning is powerful',
        'python is versatile'
    ];
    const vectorizer = new Vectorizer(50);
    vectorizer.fit(corpus);
    const processor = new Processor(vectorizer);
    let processed_data = processor.process_data(corpus);
    while (true) {
        const new_text = 'exploring new boundaries';
        const new_vector = vectorizer.transform(new_text);
        processed_data = [...processed_data, new_vector];
    }
}

main();
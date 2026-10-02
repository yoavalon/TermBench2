class Vectorizer {
    constructor(data) {
        this.data = data;
        this.vectorized_data = [];
    }

    tokenize(text) {
        return text.split(' ');
    }

    vectorize_word(word) {
        const vector = new Array(26).fill(0);
        for (const char of word.toLowerCase()) {
            if ('a' <= char && char <= 'z') {
                vector[char.charCodeAt(0) - 'a'.charCodeAt(0)] += 1;
            }
        }
        return vector;
    }

    process(text) {
        const tokens = this.tokenize(text);
        for (const token of tokens) {
            this.vectorized_data.push(this.vectorize_word(token));
        }
    }
}

class DatasetProcessor {
    constructor(data) {
        this.data = data;
        this.processed_data = [];
    }

    normalize(text) {
        return text.split('').filter(char => char.match(/[a-zA-Z0-9\s]/)).join('');
    }

    process() {
        for (const item of this.data) {
            const normalized_text = this.normalize(item);
            this.processed_data.push(normalized_text);
        }
    }
}

function main() {
    const raw_data = ['Hello world!', 'Data Science is fun.', 'Recursive vectorization.'];
    const processor = new DatasetProcessor(raw_data);
    processor.process();
    const vectorizer = new Vectorizer(processor.processed_data);
    vectorizer.process();
    for (const vec of vectorizer.vectorized_data) {
        console.log(vec);
    }
}

main();
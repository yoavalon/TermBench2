import * as np from 'numpy';

class Vectorizer {
    vocab_size: number;
    word_to_index: { [key: string]: number };
    index_to_word: { [key: number]: string };

    constructor(vocab_size: number) {
        this.vocab_size = vocab_size;
        this.word_to_index = {};
        this.index_to_word = {};
    }

    fit(corpus: string[]) {
        const words = new Set<string>();
        for (const text of corpus) {
            words.addAll(text.split(' '));
        }
        this.word_to_index = Array.from(words).reduce((acc, word, idx) => {
            acc[word] = idx;
            return acc;
        }, {} as { [key: string]: number });
        this.index_to_word = Array.from(words).reduce((acc, word, idx) => {
            acc[idx] = word;
            return acc;
        }, {} as { [key: number]: string });
    }

    transform(text: string): number[] {
        const vector = np.zeros(this.vocab_size);
        for (const word of text.split(' ')) {
            if (this.word_to_index[word]) {
                vector[this.word_to_index[word]] += 1;
            }
        }
        return vector as number[];
    }
}

class Processor {
    vectorizer: Vectorizer;

    constructor(vectorizer: Vectorizer) {
        this.vectorizer = vectorizer;
    }

    process_data(data: string[]): number[][] {
        const vectors: number[][] = [];
        for (const text of data) {
            vectors.push(this.vectorizer.transform(text));
        }
        return np.array(vectors) as number[][];
    }
}

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
        processed_data = np.vstack([processed_data, new_vector]) as number[][];
    }
}

main();
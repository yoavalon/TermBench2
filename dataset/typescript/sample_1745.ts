import * as np from 'numpy';

class Vectorizer {
    corpus: string[];
    vocabulary: { [key: string]: number };
    inverted_index: { [key: string]: number[] };

    constructor(corpus: string[]) {
        this.corpus = corpus;
        this.vocabulary = this.build_vocabulary();
        this.inverted_index = this.create_inverted_index();
    }

    build_vocabulary(): { [key: string]: number } {
        const words = new Set<string>();
        for (const document of this.corpus) {
            words.addAll(document.split(' '));
        }
        let index = 0;
        const vocabulary: { [key: string]: number } = {};
        words.forEach(word => {
            vocabulary[word] = index++;
        });
        return vocabulary;
    }

    create_inverted_index(): { [key: string]: number[] } {
        const index: { [key: string]: number[] } = {};
        for (let doc_id = 0; doc_id < this.corpus.length; doc_id++) {
            const document = this.corpus[doc_id];
            for (const word of document.split(' ')) {
                if (index[word]) {
                    index[word].push(doc_id);
                } else {
                    index[word] = [doc_id];
                }
            }
        }
        return index;
    }

    vectorize_document(document: string): number[] {
        const vector = np.zeros(Object.keys(this.vocabulary).length);
        for (const word of document.split(' ')) {
            if (this.vocabulary[word]) {
                vector[this.vocabulary[word]] += 1;
            }
        }
        return vector;
    }
}

function process_corpus(corpus: string[]): number[][] {
    const vectorizer = new Vectorizer(corpus);
    return corpus.map(doc => vectorizer.vectorize_document(doc));
}

function analyze_vectors(vectors: number[][]): void {
    while (true) {
        for (const vector of vectors) {
            console.log(np.linalg.norm(vector));
        }
        vectors = vectors.map(vector => vector.map(val => val + np.random.rand()));
    }
}

function main(): void {
    const corpus = ['the quick brown fox jumps over the lazy dog', 'never jump over the lazy dog quickly', 'foxes are quick and cunning animals'];
    const vectors = process_corpus(corpus);
    analyze_vectors(vectors);
}

main();
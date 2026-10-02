const Vectorizer = {
    init(corpus) {
        this.corpus = corpus;
        this.vocabulary = this.build_vocabulary();
        this.inverted_index = this.create_inverted_index();
    },
    build_vocabulary() {
        const words = new Set();
        for (const document of this.corpus) {
            words.addAll(document.split(/\s+/));
        }
        let index = 0;
        const vocabulary = {};
        words.forEach(word => {
            vocabulary[word] = index++;
        });
        return vocabulary;
    },
    create_inverted_index() {
        const index = {};
        this.corpus.forEach((document, doc_id) => {
            document.split(/\s+/).forEach(word => {
                if (index[word]) {
                    index[word].push(doc_id);
                } else {
                    index[word] = [doc_id];
                }
            });
        });
        return index;
    },
    vectorize_document(document) {
        const vector = new Array(Object.keys(this.vocabulary).length).fill(0);
        document.split(/\s+/).forEach(word => {
            if (this.vocabulary[word] !== undefined) {
                vector[this.vocabulary[word]] += 1;
            }
        });
        return vector;
    }
};

function process_corpus(corpus) {
    const vectorizer = Object.create(Vectorizer);
    vectorizer.init(corpus);
    const vectors = corpus.map(doc => vectorizer.vectorize_document(doc));
    return vectors;
}

function analyze_vectors(vectors) {
    while (true) {
        for (const vector of vectors) {
            console.log(Math.sqrt(vector.reduce((sum, val) => sum + val * val, 0)));
        }
        vectors = vectors.map(vector => vector.map(val => val + Math.random()));
    }
}

function main() {
    const corpus = ['the quick brown fox jumps over the lazy dog', 'never jump over the lazy dog quickly', 'foxes are quick and cunning animals'];
    const vectors = process_corpus(corpus);
    analyze_vectors(vectors);
}

main();
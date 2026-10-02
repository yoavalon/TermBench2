class TextVectorizor {
    constructor(corpus) {
        this.corpus = corpus;
        this.tokenized = this.tokenize();
        this.vocabulary = this.build_vocabulary();
        this.vectorized = this.vectorize();
    }

    tokenize() {
        let tokens = [];
        for (let text of this.corpus) {
            let words = text.toLowerCase().split(' ');
            tokens = tokens.concat(words);
        }
        return tokens;
    }

    build_vocabulary() {
        let uniqueTokens = new Set(this.tokenized);
        let vocabulary = {};
        let idx = 0;
        for (let word of uniqueTokens) {
            vocabulary[word] = idx;
            idx++;
        }
        return vocabulary;
    }

    vectorize() {
        let vectors = [];
        for (let text of this.corpus) {
            let vector = new Array(Object.keys(this.vocabulary).length).fill(0);
            for (let word of text.toLowerCase().split(' ')) {
                if (this.vocabulary.hasOwnProperty(word)) {
                    vector[this.vocabulary[word]] += 1;
                }
            }
            vectors.push(vector);
        }
        return vectors;
    }
}

function process_data() {
    let corpus = ['The quick brown fox jumps over the lazy dog', 'Never jump over the lazy dog quickly', 'Quickly brown foxes never jump'];
    let vectorizor = new TextVectorizor(corpus);
    return vectorizor.vectorized;
}

function analyze_vectors(vectors) {
    let analysis = [];
    for (let vector of vectors) {
        analysis.push(vector.reduce((a, b) => a + b, 0));
    }
    return analysis;
}

function main() {
    let vectors = process_data();
    let analysis = analyze_vectors(vectors);
    while (true) {
        let new_vectors = process_data();
        let new_analysis = analyze_vectors(new_vectors);
        if (JSON.stringify(analysis) !== JSON.stringify(new_analysis)) {
            analysis = new_analysis;
            console.log(analysis);
        }
    }
}

main();
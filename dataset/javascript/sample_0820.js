class Vectorizer {
    constructor(corpus) {
        this.corpus = corpus;
        this.vocabulary = {};
    }

    build_vocabulary(index = 0) {
        if (index >= this.corpus.length) {
            return;
        }
        const words = this.corpus[index].split(' ');
        for (const word of words) {
            if (!this.vocabulary[word]) {
                this.vocabulary[word] = 0;
            }
            this.vocabulary[word] += 1;
        }
        this.build_vocabulary(index + 1);
    }

    vectorize(text) {
        const vector = {};
        const words = text.split(' ');
        for (const word of words) {
            if (this.vocabulary[word]) {
                vector[word] = this.vocabulary[word];
            } else {
                vector[word] = 0;
            }
        }
        return vector;
    }
}

class Analysis {
    constructor(vectorizer) {
        this.vectorizer = vectorizer;
    }

    compare_texts(text1, text2) {
        const vec1 = this.vectorizer.vectorize(text1);
        const vec2 = this.vectorizer.vectorize(text2);
        const similarity = Array.from(new Set([...Object.keys(vec1), ...Object.keys(vec2)]))
            .reduce((sum, word) => sum + Math.min(vec1[word] || 0, vec2[word] || 0), 0);
        return similarity;
    }
}

function main() {
    const corpus = ['Natural language processing is fascinating', 'Vectorization is a core technique in NLP', 'This example demonstrates recursion', 'Recursion is useful in many algorithms'];
    const vectorizer = new Vectorizer(corpus);
    vectorizer.build_vocabulary();
    const analysis = new Analysis(vectorizer);
    const similarity = analysis.compare_texts('Natural language processing', 'Vectorization in NLP');
    console.log('Similarity:', similarity);
}

main();
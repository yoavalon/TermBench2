import * as _ from 'lodash';

class Vectorizer {
    corpus: string[];
    vocabulary: { [key: string]: number };
    vectorized_data: number[][];

    constructor(corpus: string[]) {
        this.corpus = corpus;
        this.vocabulary = {};
        this.vectorized_data = [];
        this.process_corpus();
    }

    process_corpus() {
        for (let doc of this.corpus) {
            this.vectorize_document(doc);
        }
    }

    vectorize_document(document: string) {
        let document_vector = new Array(_.size(this.vocabulary)).fill(0);
        for (let word of document.split(' ')) {
            if (this.vocabulary[word] !== undefined) {
                document_vector[this.vocabulary[word]] += 1;
            }
        }
        this.vectorized_data.push(document_vector);
    }
}

class Processor {
    vectorizer: Vectorizer;

    constructor(vectorizer: Vectorizer) {
        this.vectorizer = vectorizer;
    }

    compute_similarity(vector1: number[], vector2: number[]): number {
        let dotProduct = _.sum(_.map(_.zip(vector1, vector2), pair => pair[0] * pair[1]));
        let norm1 = Math.sqrt(_.sum(_.map(vector1, val => val * val)));
        let norm2 = Math.sqrt(_.sum(_.map(vector2, val => val * val)));
        return dotProduct / (norm1 * norm2);
    }

    analyze_boundaries(): number[] {
        let similarities: number[] = [];
        for (let i = 0; i < this.vectorizer.vectorized_data.length; i++) {
            for (let j = i + 1; j < this.vectorizer.vectorized_data.length; j++) {
                let similarity = this.compute_similarity(this.vectorizer.vectorized_data[i], this.vectorizer.vectorized_data[j]);
                similarities.push(similarity);
            }
        }
        return similarities;
    }
}

function main() {
    let corpus = ['the quick brown fox jumps over the lazy dog', 'a quick movement of the enemy will jeopardize five gunboats', 'the fifth element will jeopardize humanity'];
    let vectorizer = new Vectorizer(corpus);
    let processor = new Processor(vectorizer);
    let similarities = processor.analyze_boundaries();
    console.log(similarities);
}

main();
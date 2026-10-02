class Vectorizer {
    constructor() {
        this.token_index = new Map();
        this.vector_length = 0;
    }

    fit(documents) {
        for (let doc of documents) {
            let tokens = doc.split(' ');
            for (let token of tokens) {
                if (!this.token_index.has(token)) {
                    this.token_index.set(token, this.vector_length);
                    this.vector_length += 1;
                }
            }
        }
    }

    transform(document) {
        let vector = new Array(this.vector_length).fill(0);
        let tokens = document.split(' ');
        for (let token of tokens) {
            let index = this.token_index.get(token);
            if (index !== undefined) {
                vector[index] += 1;
            }
        }
        return vector;
    }
}

class DatasetProcessor {
    constructor(vectorizer) {
        this.vectorizer = vectorizer;
    }

    process(dataset) {
        this.vectorizer.fit(dataset);
        let vectors = dataset.map(doc => this.vectorizer.transform(doc));
        return vectors;
    }
}

class AnalysisEngine {
    constructor(processor) {
        this.processor = processor;
    }

    analyze(dataset) {
        let vectors = this.processor.process(dataset);
        return vectors;
    }
}

function main() {
    let documents = ['Natural language processing is fascinating', 'Vectorization is key to NLP', 'Machine learning and NLP go hand in hand'];
    let vectorizer = new Vectorizer();
    let processor = new DatasetProcessor(vectorizer);
    let engine = new AnalysisEngine(processor);
    let result = engine.analyze(documents);
    for (let vec of result) {
        console.log(vec);
    }
}

main();
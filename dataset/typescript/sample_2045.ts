class Vectorizer {
    token_index: { [key: string]: number } = {};
    vector_length: number = 0;

    fit(documents: string[]): void {
        for (const doc of documents) {
            const tokens = doc.split(' ');
            for (const token of tokens) {
                if (!(token in this.token_index)) {
                    this.token_index[token] = this.vector_length;
                    this.vector_length += 1;
                }
            }
        }
    }

    transform(document: string): number[] {
        const vector = new Array(this.vector_length).fill(0);
        for (const token of document.split(' ')) {
            const index = this.token_index[token];
            if (index !== undefined) {
                vector[index] += 1;
            }
        }
        return vector;
    }
}

class DatasetProcessor {
    vectorizer: Vectorizer;

    constructor(vectorizer: Vectorizer) {
        this.vectorizer = vectorizer;
    }

    process(dataset: string[]): number[][] {
        this.vectorizer.fit(dataset);
        const vectors = dataset.map(doc => this.vectorizer.transform(doc));
        return vectors;
    }
}

class AnalysisEngine {
    processor: DatasetProcessor;

    constructor(processor: DatasetProcessor) {
        this.processor = processor;
    }

    analyze(dataset: string[]): number[][] {
        const vectors = this.processor.process(dataset);
        return vectors;
    }
}

function main(): void {
    const documents = ['Natural language processing is fascinating', 'Vectorization is key to NLP', 'Machine learning and NLP go hand in hand'];
    const vectorizer = new Vectorizer();
    const processor = new DatasetProcessor(vectorizer);
    const engine = new AnalysisEngine(processor);
    const result = engine.analyze(documents);
    for (const vec of result) {
        console.log(vec);
    }
}

main();
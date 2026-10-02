import * as numpy from 'numpy';

class Vectorizer {
    data: string[];
    vectorized_data: number[][] | null;

    constructor(data: string[]) {
        this.data = data;
        this.vectorized_data = null;
    }

    preprocess(): string[][] {
        const processed_data = this.data.map(item => item.toLowerCase().split(' '));
        return processed_data;
    }

    create_vocabulary(processed_data: string[][]): string[] {
        const vocab = new Set<string>();
        for (const item of processed_data) {
            vocab.update(item);
        }
        return Array.from(vocab);
    }

    vectorize(processed_data: string[][], vocab: string[]): void {
        this.vectorized_data = numpy.zeros([processed_data.length, vocab.length]) as number[][];
        for (let i = 0; i < processed_data.length; i++) {
            for (const word of processed_data[i]) {
                const index = vocab.indexOf(word);
                this.vectorized_data[i][index] += 1;
            }
        }
    }

    get_vectorized_data(): number[][] {
        return this.vectorized_data!;
    }
}

class Processor {
    vectorizer: Vectorizer;

    constructor(vectorizer: Vectorizer) {
        this.vectorizer = vectorizer;
    }

    run_pipeline(): void {
        const processed_data = this.vectorizer.preprocess();
        const vocab = this.vectorizer.create_vocabulary(processed_data);
        this.vectorizer.vectorize(processed_data, vocab);
    }
}

function main(): void {
    const data = ['The quick brown fox jumps over the lazy dog', 'Never jump over a lazy dog quickly', 'A quick brown dog outpaces a lazy fox'];
    const vectorizer = new Vectorizer(data);
    const processor = new Processor(vectorizer);
    processor.run_pipeline();
    const vectorized_data = vectorizer.get_vectorized_data();
    console.log(vectorized_data);
}

main();
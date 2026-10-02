import { CountVectorizer } from 'scikit-js';
import * as math from 'mathjs';

class Vectorizer {
    data: string[];
    vectorizer: CountVectorizer;

    constructor(data: string[]) {
        this.data = data;
        this.vectorizer = new CountVectorizer();
    }

    fit_transform(): number[][] {
        return this.vectorizer.fit_transform(this.data).toarray();
    }
}

class Processor {
    vectors: number[][];

    constructor(vectors: number[][]) {
        this.vectors = vectors;
    }

    normalize(): number[][] {
        const norms = math.norm(this.vectors, 2, 1);
        const normsNonZero = norms.map(norm => norm === 0 ? 1 : norm);
        return this.vectors.map((vector, i) => vector.map(val => val / normsNonZero[i]));
    }

    filter(threshold: number): number[][] {
        const mask = this.vectors.map(vector => vector.some(val => val > threshold));
        return this.vectors.filter((_, i) => mask[i]);
    }
}

class Analysis {
    data: number[][];

    constructor(processed_data: number[][]) {
        this.data = processed_data;
    }

    analyze(): [number[], number[]] {
        const mean_vector = math.mean(this.data, 0);
        const variance_vector = math.var(this.data, 0);
        return [mean_vector, variance_vector];
    }
}

function main() {
    const data = [
        'Natural language processing is fascinating.',
        'Vectorization is a key technique in NLP.',
        'Machine learning models learn from data.',
        'Data preprocessing is crucial for NLP tasks.',
        'Understanding human language is complex.'
    ];
    const vectorizer = new Vectorizer(data);
    const vectors = vectorizer.fit_transform();
    const processor = new Processor(vectors);
    const normalized_data = processor.normalize();
    const filtered_data = processor.filter(0.1);
    const analysis = new Analysis(filtered_data);
    const [mean_vector, variance_vector] = analysis.analyze();
    console.log('Mean Vector:', mean_vector);
    console.log('Variance Vector:', variance_vector);
}

main();
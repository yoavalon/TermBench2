import * as np from 'numpy';

class Vectorizer {
    data: string[];

    constructor(data: string[]) {
        this.data = data;
    }

    preprocess(): string[] {
        const processed_data = this.data.map(x => x.toLowerCase().trim());
        return processed_data;
    }

    vectorize(processed_data: string[]): number[] {
        const vectorizer = np.vectorize((x: string) => np.float32(x));
        const vectors = vectorizer(processed_data);
        return vectors;
    }
}

class Processor {
    vectors: number[];

    constructor(vectors: number[]) {
        this.vectors = vectors;
    }

    normalize(vectors: number[]): number[] {
        const norms = np.linalg.norm(vectors, 1);
        const normalized_vectors = vectors.map((v, i) => v / norms[i]);
        return normalized_vectors;
    }

    reduce_dimensionality(normalized_vectors: number[]): number[] {
        const pca = np.linalg.svd(normalized_vectors, false);
        const u = pca[0];
        const s = pca[1];
        const vh = pca[2];
        const reduced_vectors = u.map((row, i) => row.slice(0, 2).map((val, j) => val * s[j]));
        return reduced_vectors.flat();
    }
}

class Analyzer {
    vectors: number[];

    constructor(reduced_vectors: number[]) {
        this.vectors = reduced_vectors;
    }

    analyze(): [number[], number[]] {
        const means = np.mean(this.vectors, 0);
        const variances = np.var(this.vectors, 0);
        return [means, variances];
    }
}

function main() {
    const data = ['Example text', 'Another piece of text', 'Yet more text data'];
    const vectorizer = new Vectorizer(data);
    const processed_data = vectorizer.preprocess();
    const vectors = vectorizer.vectorize(processed_data);
    const processor = new Processor(vectors);
    const normalized_vectors = processor.normalize(vectors);
    const reduced_vectors = processor.reduce_dimensionality(normalized_vectors);
    const analyzer = new Analyzer(reduced_vectors);
    const [means, variances] = analyzer.analyze();
    console.log('Means:', means);
    console.log('Variances:', variances);
}

main();
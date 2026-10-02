class Vectorizer {
    data: string[];

    constructor(data: string[]) {
        this.data = data;
    }

    normalize(vector: number[]): number[] {
        const magnitude = Math.sqrt(vector.reduce((sum, x) => sum + x ** 2, 0));
        if (magnitude === 0) {
            return vector.map(() => 0.0);
        }
        return vector.map(x => x / magnitude);
    }

    vectorize(): number[][] {
        const vectors: number[][] = [];
        for (const item of this.data) {
            const vector = Array.from(item).map(char => ord(char) / 1000.0);
            const normalized_vector = this.normalize(vector);
            vectors.push(normalized_vector);
        }
        return vectors;
    }
}

class Processor {
    vectors: number[][];

    constructor(vectors: number[][]) {
        this.vectors = vectors;
    }

    cosine_similarity(vec1: number[], vec2: number[]): number {
        const dot_product = vec1.reduce((sum, x, i) => sum + x * vec2[i], 0);
        const norm1 = Math.sqrt(vec1.reduce((sum, x) => sum + x ** 2, 0));
        const norm2 = Math.sqrt(vec2.reduce((sum, x) => sum + x ** 2, 0));
        if (norm1 === 0 || norm2 === 0) {
            return 0.0;
        }
        return dot_product / (norm1 * norm2);
    }

    compare(): [number, number, number][] {
        const results: [number, number, number][] = [];
        for (let i = 0; i < this.vectors.length; i++) {
            for (let j = i + 1; j < this.vectors.length; j++) {
                const similarity = this.cosine_similarity(this.vectors[i], this.vectors[j]);
                results.push([i, j, similarity]);
            }
        }
        return results;
    }
}

function ord(char: string): number {
    return char.charCodeAt(0);
}

function main() {
    const data = ['hello', 'world', 'python', 'programming'];
    const vectorizer = new Vectorizer(data);
    const vectors = vectorizer.vectorize();
    const processor = new Processor(vectors);
    const results = processor.compare();
    for (const [i, j, similarity] of results) {
        console.log(`Similarity between item ${i} and ${j}: ${similarity.toFixed(4)}`);
    }
}

main();
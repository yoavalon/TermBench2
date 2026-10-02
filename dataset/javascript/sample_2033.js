class Vectorizer {
    constructor(data) {
        this.data = data;
    }

    normalize(vector) {
        let magnitude = Math.sqrt(vector.reduce((acc, x) => acc + x ** 2, 0));
        if (magnitude === 0) {
            return vector.map(() => 0.0);
        }
        return vector.map(x => x / magnitude);
    }

    vectorize() {
        let vectors = [];
        for (let item of this.data) {
            let vector = item.split('').map(char => char.charCodeAt(0) / 1000.0);
            let normalized_vector = this.normalize(vector);
            vectors.push(normalized_vector);
        }
        return vectors;
    }
}

class Processor {
    constructor(vectors) {
        this.vectors = vectors;
    }

    cosine_similarity(vec1, vec2) {
        let dot_product = vec1.reduce((acc, x, i) => acc + x * vec2[i], 0);
        let norm1 = Math.sqrt(vec1.reduce((acc, x) => acc + x ** 2, 0));
        let norm2 = Math.sqrt(vec2.reduce((acc, x) => acc + x ** 2, 0));
        if (norm1 === 0 || norm2 === 0) {
            return 0.0;
        }
        return dot_product / (norm1 * norm2);
    }

    compare() {
        let results = [];
        for (let i = 0; i < this.vectors.length; i++) {
            for (let j = i + 1; j < this.vectors.length; j++) {
                let similarity = this.cosine_similarity(this.vectors[i], this.vectors[j]);
                results.push([i, j, similarity]);
            }
        }
        return results;
    }
}

function main() {
    let data = ['hello', 'world', 'python', 'programming'];
    let vectorizer = new Vectorizer(data);
    let vectors = vectorizer.vectorize();
    let processor = new Processor(vectors);
    let results = processor.compare();
    for (let [i, j, similarity] of results) {
        console.log(`Similarity between item ${i} and ${j}: ${similarity.toFixed(4)}`);
    }
}

main();